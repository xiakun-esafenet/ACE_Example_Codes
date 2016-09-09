#ifndef	_ACE_HELLO_SERVER_H
#define	_ACE_HELLO_SERVER_H

#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"

//使用Reactor框架的步骤
//1. 从ACE_Event_Handler派生子类，并重载特定事件的回调方法(如handle_input, handle_timeout)
//2. 向ACE_Reactor注册刚才创建的ACE_Event_Handler子类
//3. 运行ACE_Reactor事件循环

//ACE_Svc_Handler继承自ACE_Task,是一个类模板，定义其子类时，要指定模板类型
//PEER_STREAM:底层传递数据流的类型，Socket连接时使用ACE_SOCK_STREAM
//SYNCH_STRATEGY:同步策略，ACE_NULL_SYNCH为无同步
//重载handle_*()方法
class HelloServerHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
public:
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> Super;
//子类open中打印log，所以要实现它
	virtual int open(void* =0 ); 
	virtual int handle_input(ACE_HANDLE	fd = ACE_INVALID_HANDLE);
private:
	ACE_TCHAR	m_szPeerName[256];
};
#endif