#pragma once
#include <string>
#include <stack>
#include <vector>
#include <map>
#include "Email.h"
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
	std::stack<Email, std::vector<Email>> getInbox() { return User::inbox; }

	//readEmail
	//markAsUnRead
	//viewContacts
	//AddToContacts
	//RemoveFromContacts
	//CreateNewEmail - choose contact - create email object
	//SendEmail -  "send" to contact
	//deleteEmail
	//deleteAllEmails
	//searchBy date
	//searchBy subject
	//searchBy presence of attachment



private:
	std::string name, password, emailAddress;
	std::stack<Email, std::vector<Email>> inbox;
	std::map<std::string, std::string> contactList;
};
