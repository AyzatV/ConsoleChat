#include "Users.h"

namespace aiafpb1
{
	// ���������� ���������� � ��������� "�������" ���������
	void User::clear()
	{
		this->log.clear();
		this->pword.clear();
		this->name.clear();
		this->last_seen.clear();
	}

	// "������" ��� ������������ � ������� (���--�����) ��� ����������� �������������, �.�. ����� ������������� ����� ���������
	std::string User::fullName() const { return (name + "--" + log); }
}