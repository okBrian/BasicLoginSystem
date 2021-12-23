#include "LoginSystem.h"

bool operator==(const User& user1, const User& user2)
{
	return (user1.Username == user2.Username);
}

LoginSystem::LoginSystem()
	: numUser(0)
{
}

const bool LoginSystem::loginUser(const User& userInput) 
{
	for (std::map<unsigned int, User>::iterator it = IdUser.begin(); it != IdUser.end(); it++)
	{
		if (userInput == it->second)
			return true;
	}
	return false;
}

void LoginSystem::addUser(unsigned int ID, User userInfo)
{
	if ((IdUser.find(ID) != IdUser.end()) && (IdUser.find(ID)->second == userInfo))
		std::cout << "ID or userInfo Value already taken" << std::endl;
	else
		IdUser.insert(std::pair<unsigned int, User>(ID, userInfo));
}

const User LoginSystem::getUser(unsigned int& ID) const
{
	return IdUser.find(ID)->second;
}

const std::string LoginSystem::getAllUser() 
{
	std::string outString;
	for (std::map<unsigned int, User>::iterator it = IdUser.begin(); it != IdUser.end(); it++)
	{
		outString.append(std::to_string(it->first) + std::string(" => ") + it->second.Username + " | " + it->second.Password + "\n");
	}
	return outString;
}

