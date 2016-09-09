#include "ace/Reactor.h"
#include "ace/Connector.h"
#include "ace/SOCK_Connector.h"
#include "ace_hello_client.h"

int main(int argc, char* argv[])
{
	ACE_INET_Addr	peer_addr(9123, "192.168.8.194");

	ACE_Connector<HelloClientHandler,ACE_SOCK_Connector> client;

	for(int i=0; i<3; i++)
	{
		HelloClientHandler* handler = NULL;
		if( client.connect(handler, peer_addr)==-1 )
		{
			ACE_DEBUG((LM_DEBUG, ACE_TEXT("%T, [%P|%t], %p, Connection %d Failed!\n"),
				i));
			return -1;
		}
	}

	ACE_Reactor::instance()->run_reactor_event_loop();

	return 0;
}

