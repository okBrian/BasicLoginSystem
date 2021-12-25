#include <map>
#include <fstream>

#include "User.h"

class LoginSystem : User
{
	protected:
		std::map<unsigned int, User> IdUser;
	private:
		std::fstream fs;
	public:

		bool loginUser(const User& userInput);
		bool signInUser();
		void addUser(unsigned int ID, User userInfo);
		const User getUser(unsigned int& ID) const;
		const std::string getAllUser();
		void makeUserFile(unsigned int ID);
};