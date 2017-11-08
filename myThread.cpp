#include "include.h"


recFrame_t::recFrame_t(int startofframe,int endofframe,int readnum,showpic* Pwindows)
        :wxThread(),state(state_ini),rawdate(NULL),sof(startofframe),eof(endofframe),toread(readnum),pwindows(Pwindows),readnum(0)
{
}
void* recFrame_t::Entry()
{
    static int n;//控制要读取的字节数
    static char* addtowrite;//保存偏移量，保存数据时使用
    char ch;//判断帧头帧尾用
    myserialport->ClearRecBuff();
    while(!TestDestroy())
    {
        switch(state)
        {
            case state_ini: if(myserialport->RXCHAR_Init()) state=state_wait;else state=state_err;break;
            case state_wait: if(myserialport->WaitForEventOccur()) {myserialport->Clean_RXCHAR();state=state_findheader;}break;
            case state_findheader:
                if(myserialport->Read(&ch,1)>0)
                {
                    readnum++;
                    if(ch==sof)
                        state=state_recdate;
                }
                else
                {
                    Sleep(50);
                    switch(myserialport->Read(&ch,1))
                    {
//                    case -1:
                    case 0: state=state_ini;break;
                    case 1: if(ch==sof) state=state_recdate;readnum++;break;
                    default: state=state_err;break;
                    }
                }
                break;
            case state_recdate:
                if(!rawdate)
                {
                    addtowrite=rawdate=new char[toread];
                    n=toread;
                }
                int res;
                if(res=myserialport->Readv(addtowrite,n,100))
                {
                    readnum+=res;
                    n-=res;
                    if(!n)//若已经读完一个帧的数据部分
                    {
                        if(myserialport->GetCacheByteNum()>0)
                        {
                            myserialport->Read(&ch,1);
                            if(ch!=eof) goto lose;
                        }
                        else
                        {
                            Sleep(50);
                            if(myserialport->GetCacheByteNum()>0)
                            {
                                myserialport->Read(&ch,1);
                                if(ch!=eof) goto lose;
                            }
                            else goto lose;
                        }
                        ProFrame_t* prothread=new ProFrame_t(rawdate,toread,pwindows);
                        if(wxTHREAD_NO_ERROR != prothread->Create())
                        {
                            state=state_err;
                            break;
                        }

                        if(wxTHREAD_NO_ERROR != prothread->Run())
                        {
                            state=state_err;
                            break;
                        }
                        rawdate=NULL;
                        state=state_findheader;
                        break;
                    }
                    addtowrite+=res;
                }
                else//一个都没读取到，超时
                {
lose:               delete[] rawdate;
                    rawdate=NULL;
                    state=state_ini;
                }
                break;
            default: wxMessageBox("Err Occur");return (wxThread::ExitCode)0;
        }
        wxCommandEvent* event=new wxCommandEvent(wxEVT_READNUM_UPDATE);
        event->SetClientData((void*)&readnum);
        wxQueueEvent(pwindows,event);
    }
    return (wxThread::ExitCode)0;
}
void recFrame_t::OnExit()
{
    if(rawdate) delete[] rawdate;
    myserialport->Clean_RXCHAR();
}

/** \brief 处理帧数据，发送
 *
 * \param
 * \param
 * \return
 *
 */

ProFrame_t::ProFrame_t(char* dateadd,int datenum,showpic* Windows)
            :wxThread(),rawdate(dateadd),rawdatenum(datenum),windows(Windows)
{
}
void* ProFrame_t::Entry()
{
    imgdate=(unsigned char*)malloc(3*rawdatenum*sizeof(char));//无符号数型变量才能用于构造wximage，char会使得图像全黑
    for(int i=0;i<rawdatenum;i++)
    {
        for(char m=0;m<3;m++)
        {
            (*imgdate)=rawdate[i];
            imgdate++;
        }
    }
    delete[] rawdate;
    imgdate=imgdate-rawdatenum*3;
    wxCommandEvent* event=new wxCommandEvent(wxEVT_POINTER_ARR,wxID_ANY);
    event->SetClientData((void*)imgdate);
    wxQueueEvent(windows,event);
    return (wxThread::ExitCode)0;
}
recdate_t::recdate_t(showdate* Parent,wxTextCtrl* TextCtrl,datemode& Mode,bool& Space)
        :wxThread(),parent(Parent),textctrl(TextCtrl),mode(Mode),space(Space),state(state_ini),readnum(0)
{
}
recdate_t::~recdate_t()
{
    myserialport->Clean_RXCHAR();
}

void* recdate_t::Entry()
{
    char ch;
    int res;
    char* str;
    myserialport->ClearRecBuff();
    while(!TestDestroy())
    {
        switch(state)
        {
            case state_ini: if(myserialport->RXCHAR_Init()) state=state_wait;else state=state_err;break;
            case state_wait: if(myserialport->WaitForEventOccur()) {myserialport->Clean_RXCHAR();state=state_recdate;}break;
            case state_recdate:
                Sleep(100);
                if((res=myserialport->GetCacheByteNum())>0)
                {
                    static bool flag=false;
                    static char headchar;
                    readnum+=res;
                    if(mode==cha)
                    {
                        if(flag)//上次有汉字读了一半
                        {
                            str=(char*)malloc(res*sizeof(char)+1+1);
                            *(str+res+1)=0;
                            str[0]=headchar;
                            myserialport->Read(str+1,res);
                            if(*(str+res)<0) {headchar=*(str+res);*(str+res)=0;flag=true;}
                            else flag=false;
                        }
                        else
                        {
                            str=(char*)malloc(res*sizeof(char)+1);
                            *(str+res)=0;
                            myserialport->Read(str,res);
                            if(*(str+res-1)<0) {headchar=*(str+res-1);*(str+res-1)=0;flag=true;}
                        }
                        *textctrl<<str;
                        free(str);
                        if(space) *textctrl<<" ";
                    }
                    else
                    {
                        for(;res&&!TestDestroy();res--)
                        {
                            myserialport->Read(&ch,1);
                            switch(mode)
                            {
                            case dec: *textctrl<<(int)(unsigned char)ch;break;
                            case hex: *textctrl<<wxString::Format("%#02X",(unsigned char)ch);break;
                            default: wxLogError("an err occur");break;
                            }
                            if(space) *textctrl<<" ";
                        }
                        if(flag) flag=false;
                    }
                    wxCommandEvent* event=new wxCommandEvent(wxEVT_READNUM_UPDATE);
                    event->SetClientData((void*)&readnum);
                    wxQueueEvent(parent,event);
                }
                else state=state_ini;
                break;
            default: wxMessageBox("Err Occur");return (wxThread::ExitCode)0;
        }
    }
    return (wxThread::ExitCode)0;
}



