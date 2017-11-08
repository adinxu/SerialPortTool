#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include "mySerialPort.h"
#include "wx/config.h"

#include "ShowDate.h"
#include "ShowPic.h"
#include "myStatusBar.h"
#include "myThread.h"

#define USE_CUSTOM_FOUNT
#define USE_CUSTOM_CURSOR

extern ctb::mySerialPort* const myserialport;
extern wxConfig* const myconfig;
#endif // INCLUDE_H_INCLUDED
