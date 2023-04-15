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

	User& User::operator=(const User& u)
	{
		if (&u != this)
		{
			log = u.log;
			pword = u.pword;
			name = u.name;
			last_seen = u.last_seen;
		}
		return *this;
	}

	// ����� � ����� ������ ������������, ������������ ��� �������� ��� ����������� ������������
	std::ostream& operator<<(std::ostream& out, const User& u)
	{
		out << " �����: " << u.log << std::endl;
		out << "������: " << u.pword << std::endl;
		out << "   ���: " << u.name << std::endl;
		return out;
	}

	Users::Users() {}
	Users::~Users() {}

	// ���������� ������������ � ������
	size_t Users::add(const User& u)
	{
		m_users.add_last(u);
		return m_users.size() - 1;
	}

	// �������� ������� ��������� ������������� ������ ����
	void Users::fixTime(size_t index) { m_users[index].last_seen.renew(); }

	// �������� ��� ������ ������������ �� ����� (����� User& c), ���������� �� ��������� � TArray.tryGetOne ����� ������� nameFound (��. ����)
	bool Users::selectByName(const User& u, User& c) { return (u.log == c.log || u.name == c.name); }
}