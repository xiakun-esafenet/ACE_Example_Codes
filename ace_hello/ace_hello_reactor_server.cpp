#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace_hello_server.h"

int main(int argc, char* argv[])
{
	ACE_INET_Addr	port_to_listen(9123);

//以便不需要创建ACE_Acceptor子类，只需要定义其实例即可
//SVC_Handler(本例为HelloServerHandler)，指定Acceptor对应的ACE_Svc_Handler
//当有连接请求时，Acceptor会创建一个新的ACE_Svc_Handler来处理对端的事件
//PEER_ACCEPTOR(本例为ACE_SOCK_Acceptor)，被动的接受客户连接
//open方法可以启动服务器，并监听客户端事件，参数为ACE_INET_ADDR类型

	ACE_Acceptor<HelloServerHandler, ACE_SOCK_Acceptor> server;

	if( server.open(port_to_listen)<0 )
	{
		return -1;
	}

	ACE_Reactor::instance()->run_reactor_event_loop();

	return 0;
}

