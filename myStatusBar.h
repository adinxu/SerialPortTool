#ifndef MYSTATUSBAR_H_INCLUDED
#define MYSTATUSBAR_H_INCLUDED

wxDECLARE_EVENT(wxEVT_POINTER_ARR,wxCommandEvent);
wxDECLARE_EVENT(wxEVT_READNUM_UPDATE,wxCommandEvent);

class myStatusbar: public wxStatusBar
{
public:
    myStatusbar(wxWindow* parent);
    ~myStatusbar();

    void SetValue(int val);

    void onButtonClick(wxCommandEvent& event);
    void onSize(wxSizeEvent& event);
    long GetId()const {return ID_BUTTON;};
private:
    wxButton* button;
    static const long ID_BUTTON;
    friend class showdate;//使父窗口可访问按钮id
    friend class showpic;
};

#endif //
