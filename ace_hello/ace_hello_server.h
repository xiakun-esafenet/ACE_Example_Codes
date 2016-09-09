#ifndef	_ACE_HELLO_SERVER_H
#define	_ACE_HELLO_SERVER_H

#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"

//ʹ��Reactor��ܵĲ���
//1. ��ACE_Event_Handler�������࣬�������ض��¼��Ļص�����(��handle_input, handle_timeout)
//2. ��ACE_Reactorע��ղŴ�����ACE_Event_Handler����
//3. ����ACE_Reactor�¼�ѭ��

//ACE_Svc_Handler�̳���ACE_Task,��һ����ģ�壬����������ʱ��Ҫָ��ģ������
//PEER_STREAM:�ײ㴫�������������ͣ�Socket����ʱʹ��ACE_SOCK_STREAM
//SYNCH_STRATEGY:ͬ�����ԣ�ACE_NULL_SYNCHΪ��ͬ��
//����handle_*()����
class HelloServerHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
public:
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> Super;
//����open�д�ӡlog������Ҫʵ����
	virtual int open(void* =0 ); 
	virtual int handle_input(ACE_HANDLE	fd = ACE_INVALID_HANDLE);
private:
	ACE_TCHAR	m_szPeerName[256];
};
#endif