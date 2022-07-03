#pragma once
#include <string>
#include <chrono>
#include <fmt/core.h>

class User
{
public:
	const char* Username;
	const char* Description{};
private:
	const char* Password;
	bool signedIn{};
	std::chrono::high_resolution_clock clock{};
	std::chrono::high_resolution_clock::time_point startTime{};
	std::chrono::high_resolution_clock::time_point endTime{};
public:
	User(const char* Username, const char* Password, bool signedIn);

	void LogIn();
	void LogOut();

	void setDescription(const char* New_Description) { User::Description = New_Description; };
	float getTimeSignedIn();

	const char* getPassword() const { return Password; };
	const char* getDescription() const  { return Description; };

};