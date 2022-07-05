#pragma once
#include <string>
#include <chrono>
#include <memory>
#include <fmt/core.h>

class User
{
public:
	std::string Username;
	std::string Description;
private:
	std::string Password;
	bool signedIn;
	std::chrono::high_resolution_clock clock{};
	std::chrono::high_resolution_clock::time_point startTime{};
	std::chrono::high_resolution_clock::time_point endTime{};
public:
	User(const std::string& Username, const std::string& Password, bool signedIn = false);


	void LogIn();
	void LogOut();

	void setDescription(const char* New_Description) { User::Description = New_Description; };
	float getTimeSignedIn();

	inline std::string getPassword() const { return Password; };
	inline std::string getDescription() const  { return Description; };

};