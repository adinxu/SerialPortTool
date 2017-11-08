#ifndef MYSERIALPORT_H_INCLUDED
#define MYSERIALPORT_H_INCLUDED
#include "ctb-0.16/serport.h"
namespace ctb
{
   class mySerialPort:public SerialPort
   {
   public:
    DWORD GetCacheByteNum();//��ý��ջ������ַ���
    void ClearRecBuff();//��ջ�����

	void Set_RXCHAR();//���뻺�������յ����ַ�
	void Clean_RXCHAR();
	bool RXCHAR_Init();
    void Set_RXFLAG(const char eos);// ʹ��SetCommState()�������õ�DCB�ṹ�еĵȴ��ַ��ѱ��������뻺������
    void Clean_RXFLAG();
	bool RXFLAG_Init(const char sof);
	bool WaitForEventOccur();

   private:
		//GetCacheByteNum()��
        DWORD dwErrorFlags;
        COMSTAT ComStat;
    };
}
#endif // MYSERIALPORT_H_INCLUDED


