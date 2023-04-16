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

	// вывод параметров сообщения в поток, используется для вывода списка сообщений
	std::ostream& operator<<(std::ostream& out, const Message& m)
	{
		out << std::endl << "отправлено " << m.time << " пользователем [" << m.from_name << "]";
		if (m.to_name.empty()) { out << " для всех пользователей:"; }
		else
		{
			out << " для пользователя [" << m.to_name << "]:";
			if (!m.fresh) { out << std::endl << "[сообщение прочитано получателем]"; }
		}
		out << std::endl << m.text << std::endl;
		return out;
	}

	Messages::Messages() {}
	Messages::~Messages() {}

}