#pragma once

#include <winsock.h>

// TCP����Ա���ڱ���˾����TCPЭ������ݴ������ר�Ŵ���˯���ǵ����󣬲�����˯���Ǻ��ڲ�������Ա����
// ������պ������ѷ��֣��������鲻̫�ã����ܻ���һЩ�������BUG
class WheatTCPServer {
public:
	// WheatTCPServer();
	// virtual ~WheatTCPServer();

	bool Init(int port);
	void CloseServer();

	void Run();

	void SendMessageToFdSet(fd_set inputFdSet, int fdMax, const char * str);
	void SendMessageToFdSet(fd_set inputFdSet, int fdMax, const char * str, size_t len);

private:
	WSADATA m_WSAData;
	SOCKET m_socket;
	sockaddr_in m_address;

	bool WSAStart();
	bool SocketInit();
	void SetServerAddress(int port);
	bool Bind();
	bool Listen();
};

