#pragma once

#include <winsock.h>
#include <vector>
#include <string>

enum class SleeperType {
	Girl,
	Boy
};

class Sleeper {
public:
	bool online = false;
	SOCKET sock;
	std::string name;
	SleeperType type = SleeperType::Boy;

	void init(bool _online, SOCKET _sock, std::string _name, SleeperType _type) {
		online = _online;
		sock = _sock;
		name = _name;
		type = _type;
	}

	void copy(Sleeper & another) {
		online = another.online;
		sock = another.sock;
		name = another.name;
		type = another.type;
	}

	void clear() {
		online = false;
	}

	SleeperType TransformIntToSleeperType(int _intval);
};

class Bed {
public:
	bool empty = true;
	Sleeper * pSleeper = &sleeper;

private:
	Sleeper sleeper;
};

// ��λ�������α���˾�Ĵ�λ������������˯���ǵĴ�λ���
class WheatBedManager {
public:

	// �Ӵ�������
	void GetupBed(int getupBedSleepId);
	
	// �ڴ���˯��
	bool SleepBed(int sleepBedSleepId, Sleeper & sleeper);

	bool IsBedEmpty(int checkBedSleepId);

	SleeperType GetSleeperType(int val);

private:
	Bed m_arrBeds[256];

};

