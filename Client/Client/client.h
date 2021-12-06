#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "global.h"

#define SERVERIP	"127.0.0.1"
#define SERVERPORT	9000
#define BUFSIZE		512

class Client
{
private:
	SOCKET sock;
	SOCKADDR_IN serveraddr;
	int retval;
	int len;
	char buf[BUFSIZE + 1];

public:
	void err_quit(const char* msg);
	void err_display(const char* msg);
	Client(const char ip[]);
	void clientConnect();
	void clientSend(int id, int cmd);
	int recvn(SOCKET s, char* buf, int len, int flags);
};

#endif