#include "User.h"

User::User(std::string Username, std::string Password, bool signedIn)
	: Username(Username), Password(Password), signedIn(signedIn)
{
}

float User::getTimeSignedIn()
{
	endTime = std::chrono::high_resolution_clock::now();
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
	startTime = std::chrono::high_resolution_clock::now();
}

void User::logOutUser()
{
	std::cout << "User Logged out" << std::endl;
	signedIn = false;
	endTime = std::chrono::high_resolution_clock::now();
}

void User::setDescription(std::string& Description)
{
	User::Description = Description;
}

const std::string User::getDescription() const
{
	return Description;
}
