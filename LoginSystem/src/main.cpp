#include <thread>
#include "LoginSystem.h"

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << "Username => " << user.Username << "\nPassword => " << user.getPassword() << std::endl;
	return os;
}

int main()
{
	using namespace std::literals::chrono_literals;

	LoginSystem ls;
	ls.addUser(1, User( "Wamen", "Password", false ));
	ls.addUser(5, User( "Goy", "Password", false));
	std::cout << ls.getAllUser() << std::endl;
	ls.loginUser("Wamen", "Password");
	std::this_thread::sleep_for(1s);
	std::cout << ls.getTimeOfUser(1) << std::endl;
	ls.signOut(1);
	ls.getTimeOfUser(1);

	ls.loginUser("Wamen", "P");


	ls.makeUserFile(1);
	ls.makeUserFile(5);
	return 0;
}