/***************************************************************
 * Name:      showpicMain.h
 * Purpose:   Defines Application Frame
 * Author:    xwd (1334585420@qq.com)
 * Created:   2017-07-09
 * Copyright: xwd ()
 * License:
 **************************************************************/

#ifndef SHOWDATE_H
#define SHOWDATE_H

//(*Headers(showdate)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

typedef enum
{
    dec,
    hex,
    cha
}datemode;
class recdate_t;
class showpic;
class myStatusbar;
class showdate: public wxFrame
{
    public:
        showdate(wxWindow* parent,wxWindowID id = -1);
        virtual ~showdate();

    private:

        //(*Handlers(showdate)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onpicmode_ButtonClick(wxCommandEvent& event);
        void Onopencom_ButtonClick(wxCommandEvent& event);
        void OnBaudrateSelect(wxCommandEvent& event);
        void Onstartrec_ButtonClick(wxCommandEvent& event);
        void Onclearrec_ButtonClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        void OnRadioButton2Select(wxCommandEvent& event);
        void OnRadioButton3Select(wxCommandEvent& event);
        void OnRadioButton1Select1(wxCommandEvent& event);
        void OnRadioButton2Select1(wxCommandEvent& event);
        void OnRadioButton3Select1(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnSaveDateClick(wxCommandEvent& event);
        //*)
        void OnReadNumUpdate(wxCommandEvent& event);
        void OnClearCountClick(wxCommandEvent& event);

        //(*Identifiers(showdate)
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON3;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBUTTON3;
        static const long ID_CHECKBOX1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON5;
        static const long ID_BUTTON4;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(showdate)
        wxRadioButton* RadioButton1;
        wxStaticText* StaticText2;
        wxRadioButton* RadioButton2;
        wxButton* clearrec_Button;
        wxButton* Button1;
        wxButton* startrec_Button;
        wxButton* picmode_Button;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxRadioButton* RadioButton3;
        wxCheckBox* CheckBox1;
        wxTextCtrl* TextCtrl1;
        wxButton* opencom_Button;
        wxChoice* Choice1;
        wxChoice* Choice2;
        //*)
        showpic* newframe;
        recdate_t* workthread;
		datemode mode;
		bool Space;
		myStatusbar* statusbar;

        DECLARE_EVENT_TABLE()
};



#endif
