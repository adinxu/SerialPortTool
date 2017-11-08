/***************************************************************
 * Name:      showpicApp.cpp
 * Purpose:   Code for Application Class
 * Author:    xwd (1334585420@qq.com)
 * Created:   2017-07-09
 * Copyright: xwd ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "App.h"
#include "include.h"
//(*AppHeaders
#include <wx/image.h>
//*)

IMPLEMENT_APP(showpicApp);
ctb::mySerialPort* const myserialport=new ctb::mySerialPort();;
wxConfig* const myconfig=new wxConfig("PicDisplay");
bool showpicApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	showdate* Frame = new showdate(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
int showpicApp::OnExit()
{
    delete myserialport;
    delete myconfig;
    return 0;
}
