#pragma once
#include <string>
#include <stack>
#include <vector>
class User
{
public:
	User();
	User(std::string name, std::string password, std::string emailAddress);
	~User();

	void setName(std::string name) { User::name = name; }
	void setPassword(std::string password) { User::password = password; }
	void setEmailAddress(std::string emailAddress) { User::emailAddress = emailAddress; }

	std::string getName() { return User::name; }
	std::string getPassword() { return User::name; }
	std::string getEmailAddress() { return User::name; }

private:
	std::string name, password, emailAddress;
	std::stack<Email, std::vector<Email>> inbox;
};

