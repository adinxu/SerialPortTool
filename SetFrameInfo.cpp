#include "wx_pch.h"
#include "SetFrameInfo.h"
#include "include.h"
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(setframeval)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(setframeval)
//*)

//(*IdInit(setframeval)
const long setframeval::ID_STATICTEXT1 = wxNewId();
const long setframeval::ID_STATICTEXT2 = wxNewId();
const long setframeval::ID_TEXTCTRL1 = wxNewId();
const long setframeval::ID_STATICTEXT3 = wxNewId();
const long setframeval::ID_STATICTEXT4 = wxNewId();
const long setframeval::ID_TEXTCTRL2 = wxNewId();
const long setframeval::ID_STATICTEXT5 = wxNewId();
const long setframeval::ID_STATICTEXT6 = wxNewId();
const long setframeval::ID_TEXTCTRL3 = wxNewId();
const long setframeval::ID_STATICTEXT7 = wxNewId();
const long setframeval::ID_STATICTEXT8 = wxNewId();
const long setframeval::ID_TEXTCTRL4 = wxNewId();
const long setframeval::ID_STATICTEXT9 = wxNewId();
const long setframeval::ID_BUTTON1 = wxNewId();
const long setframeval::ID_BUTTON2 = wxNewId();
const long setframeval::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(setframeval,wxDialog)
	//(*EventTable(setframeval)
	//*)
END_EVENT_TABLE()

setframeval::setframeval(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
            :pparent((showpic*)parent)
{
	//(*Initialize(setframeval)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));

    #ifdef USE_CUSTOM_FOUNT
    wxFont font(wxFontInfo(12).FaceName("汉仪PP体简").Light());
    SetFont(font);
    #endif // USE_CUSTOM_FOUNT

	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("参数设置"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(4, 3, 0, 0);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("帧头："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("数值"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("帧尾："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("数值"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("宽度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("像素"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("高度："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("像素"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(FlexGridSizer1, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("确认"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&setframeval::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&setframeval::OnTextCtrl2Text);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&setframeval::OnTextCtrl3Text);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&setframeval::OnTextCtrl4Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&setframeval::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&setframeval::OnButton2Click);
	//*)
    TextCtrl1->ChangeValue(wxString::Format("%i",sof=pparent->startofframe));
    TextCtrl2->ChangeValue(wxString::Format("%i",eof=pparent->endofframe));
    TextCtrl3->ChangeValue(wxString::Format("%i",width=pparent->col));
    TextCtrl4->ChangeValue(wxString::Format("%i",height=pparent->row));
    wxBitmap bitmapicon("cat_16.ico",wxBITMAP_TYPE_ICO);
    wxIcon icon;
    icon.CopyFromBitmap(bitmapicon);
    SetIcon(icon);
    #ifdef USE_CUSTOM_FOUNT
    wxCursor cursor("Arrow.ani",wxBITMAP_TYPE_CUR);
    SetCursor(cursor);
    #endif // USE_CUSTOM_FOUNT

}

setframeval::~setframeval()
{
	//(*Destroy(setframeval)
	//*)
}

int setframeval::protextctinput(wxTextCtrl* TextCtrl)
{
        wxString msg;
        long val;
        msg=TextCtrl->GetLineText(1);
        //wxMessageBox(msg);
        msg.ToLong(&val,10);
        if(val<0||val>255) return 0;
        else return val;
}
void setframeval::OnTextCtrl1Text(wxCommandEvent& event)
{
    int val;
    if(val=protextctinput(TextCtrl1))
    {
        sof=val;
    }
    else
    {
        wxMessageBox("输入数值超出范围（有效：0~255）");
        TextCtrl1->ChangeValue("1");
        sof=1;
    }
}

void setframeval::OnTextCtrl2Text(wxCommandEvent& event)
{
    int val;
    if(val=protextctinput(TextCtrl1))
    {
        eof=val;
    }
    else
    {
        wxMessageBox("输入数值超出范围（有效：0~255）");
        TextCtrl1->ChangeValue("1");
        eof=1;
    }
}

void setframeval::OnTextCtrl3Text(wxCommandEvent& event)
{
    int val;
    if(val=protextctinput(TextCtrl1))
    {
        width=val;
    }
    else
    {
        wxMessageBox("输入数值超出范围（有效：0~255）");
        TextCtrl1->ChangeValue("70");
        width=70;
    }
}

void setframeval::OnTextCtrl4Text(wxCommandEvent& event)
{
    int val;
    if(val=protextctinput(TextCtrl1))
    {
        height=val;
    }
    else
    {
        wxMessageBox("输入数值超出范围（有效：0~255）");
        TextCtrl1->ChangeValue("51");
        height=51;
    }
}

void setframeval::OnButton1Click(wxCommandEvent& event)
{
    pparent->StaticText5->SetLabelText(wxString::Format("%i",pparent->startofframe=sof));
    pparent->StaticText6->SetLabelText(wxString::Format("%i",pparent->endofframe=eof));
    pparent->StaticText7->SetLabelText(wxString::Format("%i",pparent->col=width));
    pparent->StaticText8->SetLabelText(wxString::Format("%i",pparent->row=height));
    Close();
}

void setframeval::OnButton2Click(wxCommandEvent& event)
{
    Close();
}

