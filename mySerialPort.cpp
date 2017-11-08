#include "mySerialPort.h"
namespace ctb
{
/** \brief 查看读缓冲区还有多少可读数据
 *
 * \param
 * \param
 * \return 串口读缓冲区的字节数
 *
 */
    DWORD mySerialPort::GetCacheByteNum()
    {
        ClearCommError(fd,&dwErrorFlags,&ComStat);
        return ComStat.cbInQue;
    }

    void mySerialPort::ClearRecBuff()
    {
        PurgeComm(fd,PURGE_RXCLEAR);//清空接收缓冲区
    }

    void mySerialPort::Set_RXCHAR()
    {
        DWORD Event;
        GetCommMask(fd,&Event);
        Event|=EV_RXCHAR;
        SetCommMask(fd,Event);//设定串口接收事件
    }

    void mySerialPort::Clean_RXCHAR()
    {
        DWORD Event;
        GetCommMask(fd,&Event);
        Event&=~EV_RXCHAR;
        SetCommMask(fd,Event);
    }

    bool mySerialPort::RXCHAR_Init(void)
    {
        DWORD dwEvtMask;
//        PurgeComm(fd,PURGE_RXCLEAR);//清空接收缓冲区
        Set_RXCHAR();
        if(!WaitCommEvent(fd,&dwEvtMask,&m_ov))//等待事件没有立即发生
        {
            switch(GetLastError())
            {
            case ERROR_IO_PENDING: break;
            default : return false;
            }
        }
        return true;
    }
/** \brief 设定串口监视-接收特定事件字符
            设定所用字符
 *
 * \param eos 要设置的事件字符，当读缓冲区收到此字符会触发事件监视
 * \param
 * \return
 *
 */

    void mySerialPort::Set_RXFLAG(const char eos)
    {
        DCB dcb;
        GetCommState(fd,&dcb);
        dcb.EvtChar=eos;
        SetCommState(fd,&dcb);
        DWORD Event;
        GetCommMask(fd,&Event);
        Event|=EV_RXFLAG;
        SetCommMask(fd,Event);//设定串口接收事件
    }
/** \brief 取消串口监视事件-接收特定事件字符
 *          并没有清除事件字符
 * \param
 * \param
 * \return
 *
 */

    void mySerialPort::Clean_RXFLAG()
    {
        DWORD Event;
        GetCommMask(fd,&Event);
        Event&=~EV_RXFLAG;
        SetCommMask(fd,Event);
    }
/** \brief 开始监视串口事件-特定字符
 *
 * \param sof帧头
 * \param
 * \return //有错误返回false，否则返回true
 *
 */

bool mySerialPort::RXFLAG_Init(const char sof)
{
	DWORD dwEvtMask;
	PurgeComm(fd,PURGE_RXCLEAR);//清空接收缓冲区
	Set_RXFLAG(sof);
	if(!WaitCommEvent(fd,&dwEvtMask,&m_ov))//等待事件没有立即发生
	{
		switch(GetLastError())
		{
		case ERROR_IO_PENDING: break;
		default : return false;
		}
	}
	return true;
}
/** \brief 等待事件发生，线程用
 *
 * \param
 * \param
 * \return
 */

    bool mySerialPort::WaitForEventOccur()//防阻塞。。。
    {
            ResetEvent(m_ov.hEvent);
            if(WaitForSingleObject(m_ov.hEvent,100)==WAIT_OBJECT_0) return true;
            else return false;
    }
}
