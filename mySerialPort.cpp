#include "mySerialPort.h"
namespace ctb
{
/** \brief �鿴�����������ж��ٿɶ�����
 *
 * \param
 * \param
 * \return ���ڶ����������ֽ���
 *
 */
    DWORD mySerialPort::GetCacheByteNum()
    {
        ClearCommError(fd,&dwErrorFlags,&ComStat);
        return ComStat.cbInQue;
    }

    void mySerialPort::ClearRecBuff()
    {
        PurgeComm(fd,PURGE_RXCLEAR);//��ս��ջ�����
    }

    void mySerialPort::Set_RXCHAR()
    {
        DWORD Event;
        GetCommMask(fd,&Event);
        Event|=EV_RXCHAR;
        SetCommMask(fd,Event);//�趨���ڽ����¼�
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
//        PurgeComm(fd,PURGE_RXCLEAR);//��ս��ջ�����
        Set_RXCHAR();
        if(!WaitCommEvent(fd,&dwEvtMask,&m_ov))//�ȴ��¼�û����������
        {
            switch(GetLastError())
            {
            case ERROR_IO_PENDING: break;
            default : return false;
            }
        }
        return true;
    }
/** \brief �趨���ڼ���-�����ض��¼��ַ�
            �趨�����ַ�
 *
 * \param eos Ҫ���õ��¼��ַ��������������յ����ַ��ᴥ���¼�����
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
        SetCommMask(fd,Event);//�趨���ڽ����¼�
    }
/** \brief ȡ�����ڼ����¼�-�����ض��¼��ַ�
 *          ��û������¼��ַ�
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
/** \brief ��ʼ���Ӵ����¼�-�ض��ַ�
 *
 * \param sof֡ͷ
 * \param
 * \return //�д��󷵻�false�����򷵻�true
 *
 */

bool mySerialPort::RXFLAG_Init(const char sof)
{
	DWORD dwEvtMask;
	PurgeComm(fd,PURGE_RXCLEAR);//��ս��ջ�����
	Set_RXFLAG(sof);
	if(!WaitCommEvent(fd,&dwEvtMask,&m_ov))//�ȴ��¼�û����������
	{
		switch(GetLastError())
		{
		case ERROR_IO_PENDING: break;
		default : return false;
		}
	}
	return true;
}
/** \brief �ȴ��¼��������߳���
 *
 * \param
 * \param
 * \return
 */

    bool mySerialPort::WaitForEventOccur()//������������
    {
            ResetEvent(m_ov.hEvent);
            if(WaitForSingleObject(m_ov.hEvent,100)==WAIT_OBJECT_0) return true;
            else return false;
    }
}
