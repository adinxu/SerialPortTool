#ifndef MYSERIALPORT_H_INCLUDED
#define MYSERIALPORT_H_INCLUDED
#include "ctb-0.16/serport.h"
namespace ctb
{
   class mySerialPort:public SerialPort
   {
   public:
    DWORD GetCacheByteNum();//获得接收缓冲区字符数
    void ClearRecBuff();//清空缓冲区

	void Set_RXCHAR();//输入缓冲区接收到新字符
	void Clean_RXCHAR();
	bool RXCHAR_Init();
    void Set_RXFLAG(const char eos);// 使用SetCommState()函数设置的DCB结构中的等待字符已被传入输入缓冲区中
    void Clean_RXFLAG();
	bool RXFLAG_Init(const char sof);
	bool WaitForEventOccur();

   private:
		//GetCacheByteNum()用
        DWORD dwErrorFlags;
        COMSTAT ComStat;
    };
}
#endif // MYSERIALPORT_H_INCLUDED


