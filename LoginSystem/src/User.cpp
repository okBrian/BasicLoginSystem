#include "User.h"

User::User(std::string Username, std::string Password)
	: Username(Username), Password(Password)
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

void User::timeStart()
{
	startTime = std::chrono::high_resolution_clock::now();
}

void User::timeEnd()
{
	endTime = std::chrono::high_resolution_clock::now();
}