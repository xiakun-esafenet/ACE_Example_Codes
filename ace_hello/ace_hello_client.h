#ifndef _ACE_HELLO_CLIENT_
#define _ACE_HELLO_CLIENT_

#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"

class HelloClientHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> 
{
public:
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> Super;
	virtual int open(void* = 0);
	virtual int handle_timeout(const ACE_Time_Value &time, const void* act = 0);
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
private:
	int m_iTime;
};

#endif