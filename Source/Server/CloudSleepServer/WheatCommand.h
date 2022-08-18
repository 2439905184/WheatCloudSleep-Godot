#pragma once

#include <string>

enum class WheatCommandType {
	unknown,

	name,
	type,

	sleep,
	getup,

	chat,

	move,
	pos
};

struct WheatCommand {
	WheatCommandType type = WheatCommandType::unknown;
	std::string strParam;
	int nParam[2];
};

// ָ�����Ա�����𱾹�˾�ķ���˵�ָ����������ɹ���
// ָ�����Ա��ʵһֱ������ TCP����Ա(WheatTCPServer)�������ˣ�ָ�����Ա�ڹ�˾������һͬ������ͬ�¾���TCP����Ա
class WheatCommandProgrammer {
public:

	// ����ָ��
	WheatCommand Parse(const char * buf);

	// ����ָ��������Ϣ
	const char * MakeMessage(WheatCommand & command);

private:

};

