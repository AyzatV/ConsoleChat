#include "Messages.h"

namespace aiafpb1
{
	Message& Message::operator=(const Message& m)
	{
		if (&m != this)
		{
			text = m.text;
			from_name = m.from_name;
			to_name = m.to_name;
			time = m.time;
			fresh = m.fresh;
		}
		return *this;
	}
	// ����� ���������� ��������� � �����, ������������ ��� ������ ������ ���������
	std::ostream& operator<<(std::ostream& out, const Message& m)
	{
		out << std::endl << "���������� " << m.time << " ������������� [" << m.from_name << "]";
		if (m.to_name.empty()) { out << " ��� ���� �������������:"; }
		else
		{
			out << " ��� ������������ [" << m.to_name << "]:";
			if (!m.fresh) { out << std::endl << "[��������� ��������� �����������]"; }
		}
		out << std::endl << m.text << std::endl;
		return out;
	}

	Messages::Messages() {}
	Messages::~Messages() {}


}