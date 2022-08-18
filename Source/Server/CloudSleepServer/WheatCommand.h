#pragma once

#include <vector>
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
	std::string strParam = "";
	int nParam[2] = {0};
};

// ָ�����Ա�����𱾹�˾�ķ���˵�ָ����������ɹ���
// ָ�����Ա��ʵһֱ������ TCP����Ա(WheatTCPServer)�������ˣ�ָ�����Ա�ڹ�˾������һͬ������ͬ�¾���TCP����Ա
class WheatCommandProgrammer {
public:

	// ����ָ��
	WheatCommand Parse(const char * buf);

	// ����ָ��������Ϣ
	const char * MakeMessage(WheatCommand & command);

	// �и���Ϣ
	// buf ����Ҫ�ָ����Ϣ��delimiterChar ����ָ���ţ�pieces ��ʾҪ��Ƭ�ķ�����Ĭ��0Ϊ�ָ����ÿһ��
	// ���� ("ABC$DEF$114$514", '$', 3) ���õ� "ABC" "DEF" "114$514"
	std::vector<std::string> CutMessage(const char * buf, const char delimiterChar, int pieces = 0);
	std::vector<std::string> CutMessage(const char * buf, size_t len, const char delimiterChar, int pieces = 0);

	WheatCommandType GetCommandTypeFromString(const char * sz);

private:

};

