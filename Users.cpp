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
}