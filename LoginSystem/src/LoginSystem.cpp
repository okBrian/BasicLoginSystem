#include "LoginSystem.h"

bool operator==(const User& user1, const User& user2)
{
	return ((user1.Username == user2.Username) && (user1.getPassword() == user2.getPassword()));
}

bool LoginSystem::loginUser(const std::string& Username, const std::string& Password)
{
	for (std::map<unsigned int, User>::iterator it = IdUser.begin(); it != IdUser.end(); it++)
	{
		if ((it->second.Username == Username) && (it->second.getPassword() == Password))
		{
			it->second.logInUser();
			return true;
		}
	}
	return false;
}

void LoginSystem::signOut(unsigned int ID)
{
	IdUser.find(ID)->second.logOutUser();
}

float LoginSystem::getTimeOfUser(unsigned int ID)
{
	return IdUser.find(ID)->second.getTimeSignedIn();
}

void LoginSystem::addUser(unsigned int ID, User userInput)
{
	if ((IdUser.find(ID) != IdUser.end()) && (IdUser.find(ID)->second == userInput))
		std::cout << "ID or userInfo Value already taken" << std::endl;
	else
		IdUser.insert(std::pair<unsigned int, User>(ID, userInput));
}

const User LoginSystem::getUser(unsigned int ID) const
{
	return IdUser.find(ID)->second;
}

const std::string LoginSystem::getAllUser() 
{
	std::string outString;
	for (std::map<unsigned int, User>::iterator it = IdUser.begin(); it != IdUser.end(); it++)
	{
		outString.append(std::to_string(it->first) + std::string(" => ") + it->second.Username + " | " + it->second.getPassword() + "\n");
	}
	return outString;
}

void LoginSystem::makeUserFile(unsigned int ID)
{
	fs.open(IdUser.find(ID)->second.Username, std::ios_base::out);
	std::string text = "ID -> " + std::to_string(ID) + "\nUsername -> " + IdUser.find(ID)->second.Username + "\nPassword -> " + IdUser.find(ID)->second.getPassword();
	fs.write(text.c_str(), text.length() * sizeof(char));
	fs.close();
}
