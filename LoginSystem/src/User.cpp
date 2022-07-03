#include "User.hpp"

User::User(const char* Username, const char* Password, bool signedIn)
	: Username(Username), Password(Password), signedIn(signedIn)
{
}

void User::LogIn()
{
	fmt::print("User Logged In\n");
	signedIn = true;
	startTime = std::chrono::high_resolution_clock::now();
}

void User::LogOut()
{
	fmt::print("User Logged Out\n");
	signedIn = false;
	endTime = std::chrono::high_resolution_clock::now();
}

auto User::getTimeSignedIn() -> float
{
	endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = endTime - startTime;
	return duration.count();
}