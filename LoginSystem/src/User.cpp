#include "User.hpp"

User::User(const std::string_view& Username, const std::string_view& Password, bool signedIn)
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

float User::getTimeSignedIn() 
{
	endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = endTime - startTime;
	return duration.count();
}