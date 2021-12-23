#include "LoginSystem.h"

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << "Username => " << user.Username << "\nPassword => " << user.Password << std::endl;
	return os;
}

int main()
{
	LoginSystem ls;
	ls.addUser(1, User{ "Wamen", "Password" });
	ls.addUser(5, User{ "Guy", "Password" });
	std::cout << ls.getAllUser() << std::endl;
	std::cout << ls.loginUser(User{"Wamen", "Password"}) << std::endl;
	std::cout << ls.loginUser(User{ "Women", "P" }) << std::endl;
	return 0;
}