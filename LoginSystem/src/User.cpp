#include "User.h"

User::User(std::string Username, std::string Password, bool signedIn)
	: Username(Username), Password(Password), signedIn(signedIn)
{
}

float User::getTimeSignedIn()
{
	std::chrono::duration<float> duration = endTime - startTime;
	return duration.count();
}

const std::string User::getPassword() const
{
	return Password;
}

void User::logInUser()
{
	std::cout << "User Logged in!" << std::endl;
	signedIn = true;
	timeStart();
}

void User::logOutUser()
{
	std::cout << "User Logged out" << std::endl;
	signedIn = false;
	timeEnd();
}

void User::timeStart()
{
	startTime = std::chrono::high_resolution_clock::now();
}

void User::timeEnd()
{
	endTime = std::chrono::high_resolution_clock::now();
}