/***************************************************************
 * Name:      showpicMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    xwd (1334585420@qq.com)
 * Created:   2017-07-09
 * Copyright: xwd ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include <wx/msgdlg.h>
#include "include.h"
//(*InternalHeaders(showdate)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
//(*IdInit(showdate)
const long showdate::ID_STATICTEXT1 = wxNewId();
const long showdate::ID_CHOICE1 = wxNewId();
const long showdate::ID_STATICTEXT2 = wxNewId();
const long showdate::ID_CHOICE2 = wxNewId();
const long showdate::ID_BUTTON1 = wxNewId();
const long showdate::ID_BUTTON3 = wxNewId();
const long showdate::ID_RADIOBUTTON1 = wxNewId();
const long showdate::ID_RADIOBUTTON2 = wxNewId();
const long showdate::ID_RADIOBUTTON3 = wxNewId();
const long showdate::ID_CHECKBOX1 = wxNewId();
const long showdate::ID_TEXTCTRL1 = wxNewId();
const long showdate::ID_BUTTON5 = wxNewId();
const long showdate::ID_BUTTON4 = wxNewId();
const long showdate::ID_BUTTON2 = wxNewId();
const long showdate::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(showdate,wxFrame)
    //(*EventTable(showdate)
    //*)
END_EVENT_TABLE()

showdate::showdate(wxWindow* parent,wxWindowID id)
            :workthread(NULL),mode(dec),Space(true)
{
    //(*Initialize(showdate)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer5;
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
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("串口参数"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("串口："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticBoxSizer1->Add(StaticText1, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxSize(62,22), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("COM1"));
    Choice1->Append(_("COM2"));
    Choice1->Append(_("COM3"));
    Choice1->Append(_("COM4"));
    Choice1->Append(_("COM5"));
    StaticBoxSizer1->Add(Choice1, 0, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("波特率："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBoxSizer1->Add(StaticText2, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxSize(70,22), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->Append(_("300"));
    Choice2->Append(_("600"));
    Choice2->Append(_("1200"));
    Choice2->Append(_("2400"));
    Choice2->Append(_("4800"));
    Choice2->Append(_("9600"));
    Choice2->Append(_("14400"));
    Choice2->Append(_("19200"));
    Choice2->Append(_("28800"));
    Choice2->Append(_("38400"));
    Choice2->Append(_("57600"));
    Choice2->Append(_("115200"));
    Choice2->Append(_("230400"));
    Choice2->Append(_("460800"));
    StaticBoxSizer1->Add(Choice2, 0, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(-1,-1,1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    opencom_Button = new wxButton(Panel1, ID_BUTTON1, _("打开串口"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(opencom_Button, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    picmode_Button = new wxButton(Panel1, ID_BUTTON3, _("图片模式"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer1->Add(picmode_Button, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("数据接收区"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("十进制"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton1->SetValue(true);
    BoxSizer5->Add(RadioButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("十六进制"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    BoxSizer5->Add(RadioButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton3 = new wxRadioButton(Panel1, ID_RADIOBUTTON3, _("文本"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    BoxSizer5->Add(RadioButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("追加空格"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    BoxSizer5->Add(CheckBox1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 0, wxALL|wxEXPAND, 0);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(695,252), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(TextCtrl1, 1, wxALL|wxEXPAND, 0);
    StaticBoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON5, _("保存数据"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer4->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    startrec_Button = new wxButton(Panel1, ID_BUTTON4, _("开始接收"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer4->Add(startrec_Button, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    clearrec_Button = new wxButton(Panel1, ID_BUTTON2, _("清空接收区"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(clearrec_Button, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&showdate::OnBaudrateSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showdate::Onopencom_ButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showdate::Onpicmode_ButtonClick);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&showdate::OnRadioButton1Select1);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&showdate::OnRadioButton2Select1);
    Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&showdate::OnRadioButton3Select1);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&showdate::OnCheckBox1Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showdate::OnSaveDateClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showdate::Onstartrec_ButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&showdate::Onclearrec_ButtonClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&showdate::OnClose);
    //*)
    statusbar=new myStatusbar(this);
    SetStatusBar(statusbar);
    Bind(wxEVT_READNUM_UPDATE,&showdate::OnReadNumUpdate,this);
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &showdate::OnClearCountClick, this,statusbar->GetId());
    int val=0;
    myconfig->Read("comnum",&val);
    Choice1->SetSelection(val);
    val=0;
    myconfig->Read("baudrate",&val);
    Choice2->SetSelection(val);
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
showdate::~showdate()
{
    //(*Destroy(showdate)
    //*)
    if(workthread)
    {
        workthread->Delete();
        workthread=NULL;
    }
    delete statusbar;
}

void showdate::OnClearCountClick(wxCommandEvent& event)
{
    if(workthread) workthread->ClearCount();
}

void showdate::OnReadNumUpdate(wxCommandEvent& event)
{
    statusbar->SetValue(*((int*)event.GetClientData()));
}


void showdate::Onpicmode_ButtonClick(wxCommandEvent& event)
{
    if(myserialport->IsOpen())
    {
        if(workthread)
        {
            workthread->Delete();
            workthread=NULL;
            startrec_Button->SetLabel("开始接收");
        }
        newframe=new showpic(this);
        newframe->SetPosition(this->GetPosition());
        newframe->SetSize(this->GetSize());
        this->Hide();
        newframe->Show();
    }
    else wxMessageBox( "请先打开串口","提示");
}

void showdate::Onopencom_ButtonClick(wxCommandEvent& event)//读数据线程也应关闭！！！！！
{
    if(myserialport->IsOpen())
    {
        if(workthread)
        {
            workthread->Delete();
            workthread=NULL;
            startrec_Button->SetLabel("开始接收");
        }
        myserialport->Close();
        Choice1->Enable();
        opencom_Button->SetLabel("打开串口");
    }
    else//串口未打开
    {
        wxString msg;
        long baudrate;
        msg=Choice2->GetString(Choice2->GetCurrentSelection());
        msg.ToLong(&baudrate);
        //wxMessageBox(msg);
        if(myserialport->Open(Choice1->GetCurrentSelection()+1,baudrate)>=0)
        {
            Choice1->Disable();
            opencom_Button->SetLabel("关闭串口");
        }
        else wxMessageBox( "没有发现此串口或被占用","提示");
    }
}

void showdate::OnBaudrateSelect(wxCommandEvent& event)
{
    if(myserialport->IsOpen())
    {
        wxString msg;
        long baudrate;
        msg=Choice2->GetString(Choice2->GetCurrentSelection());
        msg.ToLong(&baudrate);
        if(myserialport->SetBaudrate(baudrate)<0)
            wxMessageBox("波特率设定失败","提示");
    }
}
void showdate::Onstartrec_ButtonClick(wxCommandEvent& event)
{
    if(myserialport->IsOpen())
    {
        if(workthread)
        {
            workthread->Delete();
            workthread=NULL;
            startrec_Button->SetLabel("开始接收");
        }
        else
        {
            workthread=new recdate_t(this,TextCtrl1,mode,Space);
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
            startrec_Button->SetLabel("停止接收");
        }
    }
    else wxMessageBox( "请先打开串口","提示");
}

void showdate::Onclearrec_ButtonClick(wxCommandEvent& event)
{
    TextCtrl1->Clear();
}

void showdate::OnClose(wxCloseEvent& event)
{
    myconfig->Write("comnum",Choice1->GetSelection());
    myconfig->Write("baudrate",Choice2->GetSelection());
    event.Skip();
}

void showdate::OnRadioButton1Select1(wxCommandEvent& event)
{
    mode=dec;
}

void showdate::OnRadioButton2Select1(wxCommandEvent& event)
{
    mode=hex;
}

void showdate::OnRadioButton3Select1(wxCommandEvent& event)
{
    mode=cha;
}

void showdate::OnCheckBox1Click(wxCommandEvent& event)
{
    Space=!Space;
}

void showdate::OnSaveDateClick(wxCommandEvent& event)
{
    if(!TextCtrl1->IsEmpty())
    {
        TextCtrl1->SaveFile("savedate.txt");
    }
    else wxMessageBox("无数据可存");
}



