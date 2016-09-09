#include "ace_hello_client.h"

int HelloClientHandler::open(void* p)
{
	if( Super::open(p)==-1 )
	{
		return -1;
	}

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("%T, [%P|%t] Connection Success.\n")));
	this->m_iTime = 0;

	ACE_Time_Value	delay(2); 
	//使用reactor的schedule_timer设置超时
	return this->reactor()->schedule_timer(this, 0, ACE_Time_Value::zero, delay);
}

int HelloClientHandler::handle_timeout(const ACE_Time_Value &time, const void* act)
{
	if( ++this->m_iTime>5 )
	{
		this->peer().close_writer();

		return 0;
	}

	char szMsg[4096] = {0};
	int nBytes = ACE_OS::snprintf(szMsg, 4096, "Send Message to Server %d.",this->m_iTime);

	this->peer().send(szMsg, nBytes);

	return 0;
}

int HelloClientHandler::handle_input(ACE_HANDLE fd)
{
	char szRecvMsg[4096] = {0};

	int nRecvLen = this->peer().recv(szRecvMsg, sizeof(szRecvMsg));
	if( nRecvLen<=0 )
	{
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("%T, [%P|%t] Connection Close.\n")));
		this->reactor()->end_reactor_event_loop();
		return -1;
	}

	ACE_DEBUG((LM_DEBUG, ACE_TEXT("%T, [%P|%t] RecvMsg:%s.\n"),
		szRecvMsg));

	return 0;
}

