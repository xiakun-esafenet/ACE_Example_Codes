#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace_hello_server.h"

int main(int argc, char* argv[])
{
	ACE_INET_Addr	port_to_listen(9123);

//�Ա㲻��Ҫ����ACE_Acceptor���ֻ࣬��Ҫ������ʵ������
//SVC_Handler(����ΪHelloServerHandler)��ָ��Acceptor��Ӧ��ACE_Svc_Handler
//������������ʱ��Acceptor�ᴴ��һ���µ�ACE_Svc_Handler������Զ˵��¼�
//PEER_ACCEPTOR(����ΪACE_SOCK_Acceptor)�������Ľ��ܿͻ�����
//open���������������������������ͻ����¼�������ΪACE_INET_ADDR����

	ACE_Acceptor<HelloServerHandler, ACE_SOCK_Acceptor> server;

	if( server.open(port_to_listen)<0 )
	{
		return -1;
	}

	ACE_Reactor::instance()->run_reactor_event_loop();

	return 0;
}

