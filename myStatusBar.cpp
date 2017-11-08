#include"myStatusBar.h"
wxDEFINE_EVENT(wxEVT_POINTER_ARR,wxCommandEvent);
wxDEFINE_EVENT(wxEVT_READNUM_UPDATE,wxCommandEvent);
const long myStatusbar::ID_BUTTON = wxNewId();//自定义控件中按键id

myStatusbar::myStatusbar(wxWindow* parent)
            :wxStatusBar(parent)
{
    SetFieldsCount(3);
    int patch[3]={-1,-1,100};
    SetStatusWidths(3,patch);
    SetStatusText("RX:",0);
    SetStatusText("0",1);
    button=new wxButton(this,ID_BUTTON);
    button->SetLabel("清空计数");
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &myStatusbar::onButtonClick, this, ID_BUTTON);
    Bind(wxEVT_SIZE,&myStatusbar::onSize,this);
}
myStatusbar::~myStatusbar()
{
    delete button;
}

void myStatusbar::SetValue(int val)
{
    if(val>=0)
    SetStatusText(wxString::Format("%i",val),1);
}

void myStatusbar::onButtonClick(wxCommandEvent& event)
{
    SetStatusText("0",1);
	event.Skip();
}

void myStatusbar::onSize(wxSizeEvent& event)
{
    wxRect rect;
    GetFieldRect(2,rect);
    button->SetPosition(wxPoint(rect.x+1,rect.y+1));
    button->SetSize(wxSize(rect.width-4,rect.height-4));
}
