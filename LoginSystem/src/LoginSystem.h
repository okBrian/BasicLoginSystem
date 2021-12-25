#include <map>
#include <fstream>

#include "User.h"

class LoginSystem
{
	private:
		std::map<unsigned int, User> IdUser;
		std::fstream fs;
	public:
		bool loginUser(const std::string& Username, const std::string& Password);
		void signOut(unsigned int ID);
		float getTimeOfUser(unsigned int ID);
		void addUser(unsigned int ID, User userInput);
		const User getUser(unsigned int ID) const;
		const std::string getAllUser();
		void makeUserFile(unsigned int ID);
};