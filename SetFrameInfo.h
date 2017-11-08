#ifndef SETFRAMEINFO_H
#define SETFRAMEINFO_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(setframeval)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/panel.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(setframeval)
//*)
class showpic;
class setframeval: public wxDialog
{
	public:

		setframeval(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~setframeval();

		//(*Declarations(setframeval)
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl4;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(setframeval)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT9;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:
        int protextctinput(wxTextCtrl* TextCtrl);
		//(*Handlers(setframeval)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		showpic* pparent;
        int sof;
        int eof;
        int width;
        int height;

		DECLARE_EVENT_TABLE()
};

#endif
