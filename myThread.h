#ifndef MYTHREAD_H_INCLUDED
#define MYTHREAD_H_INCLUDED

typedef enum
{
    state_ini,
    state_wait,
    state_findheader,
    state_recdate,
    state_err
}RecState;
class showpic;
class recFrame_t: public wxThread
{
public:
    recFrame_t(int startofframe,int endofframe,int readnum,showpic* Pwindows);
    virtual void* Entry();
    void OnExit();
    void ClearCount() {readnum=0;}
private:
    RecState state;
    char* rawdate;
    const int sof;
    const int eof;
    const int toread;
    showpic* pwindows;
    int readnum;
};
class ProFrame_t:public wxThread
{
public:
    ProFrame_t(char* dateadd,int datenum,showpic* Windows);
    virtual void* Entry();
private:
    char* const rawdate;
    const int rawdatenum;
    unsigned char* imgdate;
    showpic* windows;
};
class wxTextCtrl;
class showdate;
class recdate_t:public wxThread
{
public:
    recdate_t(showdate* Parent,wxTextCtrl* TextCtrl,datemode& Mode,bool& Space);
    ~recdate_t();
    virtual void* Entry();
    void ClearCount() {readnum=0;}

private:
    showdate* parent;
    wxTextCtrl* textctrl;
    const datemode& mode;
    const bool& space;
    RecState state;
    int readnum;
};
#endif // MYTHREAD_H_INCLUDED
