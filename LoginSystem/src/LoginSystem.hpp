#pragma once
#include <map>
#include <fstream>
#include <algorithm>
#include <fmt/core.h>
#include "User.hpp"

class LoginSystem
{
private:
	std::map<unsigned int, User> IdUser{};
	std::fstream fs{};
public:
	bool LoginUser(const char* Username, const char* Password);
	void SignOutUser(unsigned int ID);

	float getTimeOfUser(unsigned int ID);
	void addUser(unsigned int ID, User userInput, const char* Description);
	std::string getAllUser() const;
	void makeUserFile(unsigned int ID);

	inline User getUser(unsigned int ID) const { return IdUser.find(ID)->second; };
};