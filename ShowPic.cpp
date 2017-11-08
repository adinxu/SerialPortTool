#include "wx_pch.h"
#include "include.h"
#include "SetFrameInfo.h"
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(showpic)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(showpic)
//*)

//(*IdInit(showpic)
const long showpic::ID_STATICTEXT1 = wxNewId();
const long showpic::ID_STATICTEXT5 = wxNewId();
const long showpic::ID_STATICTEXT2 = wxNewId();
const long showpic::ID_STATICTEXT6 = wxNewId();
const long showpic::ID_STATICTEXT3 = wxNewId();
const long showpic::ID_STATICTEXT7 = wxNewId();
const long showpic::ID_STATICTEXT4 = wxNewId();
const long showpic::ID_STATICTEXT8 = wxNewId();
const long showpic::ID_BUTTON3 = wxNewId();
const long showpic::ID_BUTTON1 = wxNewId();
const long showpic::ID_PANEL2 = wxNewId();
const long showpic::ID_BUTTON2 = wxNewId();
const long showpic::ID_BUTTON4 = wxNewId();
const long showpic::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(showpic,wxFrame)
	//(*EventTable(showpic)
	//*)
END_EVENT_TABLE()

showpic::showpic(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
        :parentframe(parent),workthread(NULL)
{
	//(*Initialize(showpic)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));

    #ifdef USE_CUSTOM_FOUNT
    wxFont font(wxFontInfo(12).FaceName("汉仪PP体简").Light());
    SetFont(font);
    #endif // USE_CUSTOM_FOUNT

	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("帧参数"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("帧头："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticBoxSizer1->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("帧尾："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticBoxSizer1->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("宽度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer1->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticBoxSizer1->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("高度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticBoxSizer1->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticBoxSizer1->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON3, _("设置参数"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	StaticBoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	datemod_Button = new wxButton(Panel1, ID_BUTTON1, _("数据模式"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer1->Add(datemod_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
	Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxSize(702,305), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer2->Add(Panel2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	startrecpic_Button = new wxButton(Panel1, ID_BUTTON2, _("开始显示"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(startrecpic_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON4, _("保存图片"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer3->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 0);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showpic::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showpic::Ondatemod_ButtonClick);
	Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&showpic::OnPanel2Paint,0,this);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showpic::Onstartrecpic_ButtonClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showpic::OnSavePicClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&showpic::OnClose);
	//*)
    statusbar=new myStatusbar(this);
    SetStatusBar(statusbar);
    Bind(wxEVT_READNUM_UPDATE,&showpic::OnReadNumUpdate,this);
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &showpic::OnClearCountClick, this,statusbar->GetId());
    Bind(wxEVT_POINTER_ARR,&showpic::OnProcessThreadEvent,this);
    wxImage img("lena.jpg");
    bitmap = wxBitmap(img);
    if(myconfig->Read("sof",&startofframe)) StaticText5->SetLabelText(wxString::Format("%i",startofframe));
    else
    {
        startofframe=1;
        StaticText5->SetLabel("1");
    }

    if(myconfig->Read("eof",&endofframe)) StaticText6->SetLabelText(wxString::Format("%i",endofframe));
    else
    {
        endofframe=1;
        StaticText6->SetLabel("1");
    }

    if(myconfig->Read("col",&col)) StaticText7->SetLabelText(wxString::Format("%i",col));
    else
    {
        col=70;
        StaticText7->SetLabel("70");
    }

    if(myconfig->Read("row",&row)) StaticText8->SetLabelText(wxString::Format("%i",row));
    else
    {
        row=51;
        StaticText8->SetLabel("51");
    }
    wxBitmap bitmapicon("cat_16.ico",wxBITMAP_TYPE_ICO);
    wxIcon icon;
    icon.CopyFromBitmap(bitmapicon);
    SetIcon(icon);

    #ifdef USE_CUSTOM_CURSOR
    wxCursor cursor("Arrow.ani",wxBITMAP_TYPE_CUR);
    SetCursor(cursor);
    #endif // USE_CUSTOM_CURSOR

	Center();
}

showpic::~showpic()
{
    if(workthread)
    {
        workthread->Delete();
        workthread=NULL;
    }
    delete statusbar;
    parentframe->SetPosition(this->GetPosition());
    parentframe->SetSize(this->GetSize());
    parentframe->Show();
	//(*Destroy(showpic)
	//*)
}

void showpic::OnClearCountClick(wxCommandEvent& event)
{
    if(workthread) workthread->ClearCount();
}

void showpic::OnReadNumUpdate(wxCommandEvent& event)
{
    statusbar->SetValue(*((int*)event.GetClientData()));
}

void showpic::OnProcessThreadEvent(wxCommandEvent& event)
{
    image.Destroy();//清除原来的图片
    image=wxImage(col,row,(unsigned char*)event.GetClientData());//生成新的图片
    bitmap = wxBitmap(image.Scale(600,400));//调整大小
    Refresh(false);
}

void showpic::Ondatemod_ButtonClick(wxCommandEvent& event)
{
    this->Close(true);
}

void showpic::Onstartrecpic_ButtonClick(wxCommandEvent& event)
{
    if(workthread)
    {
        workthread->Delete();
        workthread=NULL;
        startrecpic_Button->SetLabel("开始显示");
        Button1->Enable();
    }
    else
    {
        workthread=new recFrame_t(startofframe,endofframe,col*row,this);
        if(wxTHREAD_NO_ERROR != workthread->Create())
        {
        wxLogError("Can't create the workthread!");
        return;
        }
        if(wxTHREAD_NO_ERROR != workthread->Run())
        {
        wxLogError("Can't Run the workthread!");
        return;
        }
        startrecpic_Button->SetLabel("停止显示");
        Button1->Disable();

    }
}

void showpic::OnPanel2Paint(wxPaintEvent& event)
{
    wxPaintDC dc(Panel2);
    dc.DrawBitmap(bitmap,wxPoint(0,0));
}

void showpic::OnButton1Click(wxCommandEvent& event)
{
        newdialog=new setframeval(this);
        newdialog->ShowModal();
}

void showpic::OnClose(wxCloseEvent& event)
{
    myconfig->Write("sof",startofframe);
    myconfig->Write("eof",endofframe);
    myconfig->Write("col",col);
    myconfig->Write("row",row);
    event.Skip();
}


void showpic::OnSavePicClick(wxCommandEvent& event)
{
    bitmap.SaveFile("mypic.bmp",wxBITMAP_TYPE_BMP);
}
