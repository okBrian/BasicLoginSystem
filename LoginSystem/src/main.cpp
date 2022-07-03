#include <thread>
#include "LoginSystem.hpp"

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << "Username => " << user.Username << "\nPassword => " << user.getPassword() << std::endl;
	return os;
}

int main(int ,char**)
{
	LoginSystem ls;
	ls.addUser(1, User("Wamen", "Password", false), "My name is Wamen");
	ls.addUser(5, User( "Goy", "Password", false), "My name is Goy");
	std::cout << ls.getAllUser() << std::endl;


	ls.LoginUser("Wamen", "Password");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ls.getTimeOfUser(1) << " seconds" << std::endl;
	ls.SignOutUser(1);


	ls.getTimeOfUser(1);

	ls.makeUserFile(1);
	ls.makeUserFile(5);
	return 0;
}