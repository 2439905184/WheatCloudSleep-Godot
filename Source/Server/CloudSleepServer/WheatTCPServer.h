#pragma once

#include "WheatCommand.h"
#include "WheatBedManager.h"

#include <winsock.h>

// TCP����Ա���ڱ���˾����TCPЭ������ݴ������ר�Ŵ���˯���ǵ����󣬲�����˯���Ǻ��ڲ�������Ա����
// ������պ������ѷ��� *�޿�*���������鲻̫�ã����ܻ���һЩ�������BUG
class WheatTCPServer {
public:
	WheatTCPServer() {};
	WheatTCPServer(int port) { Init(port); };
	// virtual ~WheatTCPServer();

	bool Init(int port);
	void CloseServer();

	void Run();

	// �������� buf ������һ���µ� buf���м��� '\0' �ָ�
	void BufferCatenate(char * destBuf, const char * buf1, size_t buf1Size, const char * buf2, size_t buf2Size);

	void SendMessageToFdSet(fd_set inputFdSet, int fdMax, const char * str);
	void SendMessageToFdSet(fd_set inputFdSet, int fdMax, const char * str, size_t len);

private:
	WSADATA m_WSAData;
	SOCKET m_socket;
	sockaddr_in m_address;

	WheatCommandProgrammer * m_pCommandProgrammer = nullptr;

	WheatBedManager m_bedManager;

	bool WSAStart();
	bool SocketInit();
	void SetServerAddress(int port);
	bool Bind();
	bool Listen();
};

