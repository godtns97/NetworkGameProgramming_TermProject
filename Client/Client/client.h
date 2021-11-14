#ifndef _CLIENT_H_
#define _CLIENT_H_

// 수정 필요!!!

class Client
{
private:

public:
	Client();
	void connect();
	void sendKey(int keypress);
	void sendPlayerAccess(int ID);
	void recvGameData();
	void recvGameResult();
};

#endif