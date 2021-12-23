#include <iostream>
#include <fstream>
#include <string>
#include <map>

struct User
{
	std::string Username;
	std::string Password;
};

class LoginSystem
{
	private:
		int numUser;
		std::map<unsigned int, User> IdUser;
	public:
		LoginSystem();
		const bool loginUser(const User& userInput);
		void addUser(unsigned int ID, User userInfo);
		const User getUser(unsigned int& ID) const;
		const std::string getAllUser();
};