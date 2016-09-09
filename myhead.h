#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <assert.h>

typedef enum _bool
{
	false=0,
	true
}bool;

#define SERVER_ADDR "192.168.1.118"
#define SERVER_PORT	12345
#define LISTENQUE	(5)
#define	BUFFER_SIZE	(1024)
#define AI	AF_INET
#define SS	SOCK_STREAM
#define SOL_S SOL_SOCKET
#define SO_READDR SO_REUSEADDR	
#define ANY_ONE	INADDR_ANY

typedef struct sockaddr_in sain_t;
typedef struct sockaddr sa_t;
typedef struct stat stat_t;

