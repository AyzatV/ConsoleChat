#include "Users.h"

namespace aiafpb1
{
	// приведение параметров к начальным "нулевым" значениям
	void User::clear()
	{
		this->log.clear();
		this->pword.clear();
		this->name.clear();
		this->last_seen.clear();
	}

	// "полное" имя пользователя в формате (имя--логин) для возможности идентификации, т.к. имена пользователей могут совпадать
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

	// вывод в поток данных пользователя, используется для проверки при регистрации пользователя
	std::ostream& operator<<(std::ostream& out, const User& u)
	{
		out << " логин: " << u.log << std::endl;
		out << "пароль: " << u.pword << std::endl;
		out << "   имя: " << u.name << std::endl;
		return out;
	}
}