#include "LoginSystem.hpp"

bool LoginSystem::LoginUser(const std::string_view& Username, const std::string_view& Password)
{
	auto checkEqual = [&Username, &Password](const auto& IdPair)
	{
		const auto& [ID, user] = IdPair;
		return ((user.Username == Username) && (user.getPassword() == Password));
	};
	return std::find_if(begin(IdUser), end(IdUser), checkEqual) != std::end(IdUser);
}

void LoginSystem::SignOutUser(unsigned int ID)
{
	IdUser.find(ID)->second.LogOut();
}

float LoginSystem::getTimeOfUser(unsigned int ID)
{
	return IdUser.find(ID)->second.getTimeSignedIn();
}

void LoginSystem::addUser(unsigned int ID, User userInput, const std::string_view& Description)
{
	if (IdUser.find(ID) != IdUser.end())
		fmt::print("ID already taken\n");
	else
	{
		IdUser.try_emplace(ID, userInput);
		IdUser.find(ID)->second.setDescription(Description);
	}
}

std::string LoginSystem::getAllUser() const
{
	std::string outString{};
	for (const auto& [ID, user] : IdUser)
	{
		outString.append(fmt::format("{0} => {1} - {2}\n", ID, user.Username, user.getPassword()));
	}
	return outString;
}

void LoginSystem::makeUserFile(unsigned int ID)
{
	fs.open(IdUser.find(ID)->second.Username, std::ios_base::out);
	std::string text = fmt::format(
		"ID-> {0}\nUsername -> {1}\nPassword -> {2}\n\nDescription -> {3}", 
		ID, 
		IdUser.find(ID)->second.Username, 
		IdUser.find(ID)->second.getPassword(), 
		IdUser.find(ID)->second.Description);
	fs.write(text.c_str(), text.length() * sizeof(char));
	fs.close();
}
