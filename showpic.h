#ifndef SHOWPIC_H
#define SHOWPIC_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(showpic)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/panel.h>
	#include <wx/button.h>
	#include <wx/frame.h>
	//*)
#endif
//(*Headers(showpic)
//*)

class recFrame_t;
class ProFrame_t;
class setframeval;
class myStatusbar;
class showpic: public wxFrame
{
	public:

		showpic(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~showpic();


		//(*Declarations(showpic)
		wxStaticText* StaticText2;
		wxButton* startrecpic_Button;
		wxButton* datemod_Button;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxPanel* Panel2;
		wxStaticText* StaticText4;
		//*)
	protected:

		//(*Identifiers(showpic)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT8;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		static const long ID_PANEL2;
		static const long ID_BUTTON2;
		static const long ID_BUTTON4;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(showpic)
		void Ondatemod_ButtonClick(wxCommandEvent& event);
		void OnPanel2Paint(wxPaintEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void Onstartrecpic_ButtonClick(wxCommandEvent& event);
		void OnSavePicClick(wxCommandEvent& event);
		void Onstartrecpic_ButtonClick1(wxCommandEvent& event);
		//*)
        void OnReadNumUpdate(wxCommandEvent& event);
        void OnClearCountClick(wxCommandEvent& event);
        void OnProcessThreadEvent(wxCommandEvent& event);

        int startofframe;
        int endofframe;
        int col;
        int row;

		wxImage image;
		wxBitmap bitmap;
		wxWindow* parentframe;
		setframeval* newdialog;
        recFrame_t* workthread;
        myStatusbar* statusbar;

        friend class setframeval;//使能修改帧数据信息
		DECLARE_EVENT_TABLE()
};
#endif
