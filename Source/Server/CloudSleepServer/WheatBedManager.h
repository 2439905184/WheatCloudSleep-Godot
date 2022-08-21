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
	Sleeper();
	Sleeper(SOCKET _sock);
	Sleeper(bool _empty, SOCKET _sock,  const char * _name, SleeperType _type);

	bool empty = true;
	SOCKET sock;
	std::string name = "";
	SleeperType type = SleeperType::Boy;

	void set(bool _empty, SOCKET _sock, const char * _name, SleeperType _type) {
		empty = _empty;
		sock = _sock;
		name = _name;
		type = _type;
	}

	void copy(Sleeper & another) {
		empty = another.empty;
		sock = another.sock;
		name = another.name;
		type = another.type;
	}

	void clear() {
		empty = true;
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

	// ͨ�� SleeperType ��ֵ ����ȡ SleeperType::xxxx
	// ���� GetSleeperType(0) �᷵�� SleeperType::Girl
	SleeperType GetSleeperType(int val);

	// ͨ�� socket ������ ˯��id����������ڸ�˯�ͣ����� -1
	int FindSleeperId(SOCKET sock);

	// �Ǽ��µ�˯��
	// ����п��е� ˯��id�����滻���� ˯��id �� ˯�ͣ����û�п��е� ˯��id��push_back() һ���µ� ˯��id
	// ����Ϊ��˯��ע��� ˯��id
	int RegisterNewSleeper(Sleeper sleeper);

	// ע��˯�ͣ���˯���뿪
	void CancelSleeper(int sleeperId);
	void CancelSleeper(SOCKET sleeperSocket);

	// �����׸����е� ˯��id�����û�п��� ˯��id������ -1
	int FindEmptySleeperId();

private:
	Bed m_arrBeds[256];
	std::vector<Sleeper> m_sleepers;

};

