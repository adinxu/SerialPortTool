/***************************************************************
 * Name:      showpicApp.h
 * Purpose:   Defines Application Class
 * Author:    xwd (1334585420@qq.com)
 * Created:   2017-07-09
 * Copyright: xwd ()
 * License:
 **************************************************************/

#ifndef APP_H
#define APP_H

#include <wx/app.h>

class showpicApp : public wxApp
{
    public:
        virtual bool OnInit();
        int OnExit();
};
#endif 
