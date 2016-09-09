#include "ace_hello_server.h"

int HelloServerHandler::open(void* p)
{
//���ı丸����Ϊ��ֱ�ӵ���
	if( Super::open(p)==-1 )
	{
		return -1;
	}

	ACE_INET_Addr peerAddr;

	if( this->peer().get_remote_addr(peerAddr)==0 )
	{
		peerAddr.addr_to_string(m_szPeerName, sizeof(m_szPeerName));
		//%T:ʱ�䣬%P����id��%t�߳�id
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%T, [%P|%t] New Connection From:%s\n"),
			m_szPeerName));
	}
}

int HelloServerHandler::handle_input(ACE_HANDLE fd)
{
	char szRecvMsg[4096] = {0};

	int nRecvLen = this->peer().recv(szRecvMsg, sizeof(szRecvMsg));

	if( nRecvLen<=0 )
	{
		ACE_DEBUG((LM_ERROR, ACE_TEXT("%T, [%P|%t] Connection Close From:%s\n"),
			m_szPeerName));
		return -1;
	}

	this->peer().send(szRecvMsg, nRecvLen);

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("%T, [%P|%t] RecvMsg From:%s, Msg is:%s\n"),
		m_szPeerName, szRecvMsg));
	
//����0�����´�����Ϣ����ʱ�����ܹ����˷���������
	return 0;
}

