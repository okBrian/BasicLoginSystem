#include <iostream>
#include <string>
#include <chrono>

class User
{
	public:
		std::string Username;
		bool signedIn;
		User(std::string Username, std::string Password);
		float getTimeSignedIn();
		const std::string getPassword() const;
	private:
		std::string Password;
		std::string Description;
		std::chrono::high_resolution_clock clock;
		std::chrono::high_resolution_clock::time_point startTime;
		std::chrono::high_resolution_clock::time_point endTime;
		
		void timeStart();
		void timeEnd();
		

};