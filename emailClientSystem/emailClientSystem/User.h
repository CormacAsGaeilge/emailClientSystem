#pragma once
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <iostream>
#include "Email.h"
#include "BoxType.h"
class User
{

	int count = 0;
	friend std::ostream& operator<<(std::ostream& outStream, const User& user);
	friend std::istream& operator >> (std::istream& inStream, User& user);

public:
	User();
	User(std::string name, std::string password, std::string emailAddress);
	~User();

	void setID(int id) { User::id = id; }
	void setName(std::string name);
	void setPassword(std::string password);
	void setEmailAddress(std::string emailAddress);

	int getID() { return User::id; }
	std::string getName() { return User::name; }
	std::string getPassword() { return User::password; }
	std::string getEmailAddress() { return User::emailAddress; }
	std::stack<Email*, std::vector<Email*>> getInbox() { return User::inbox; }

	void createNewEmail(Email *email);
	void User::sendEmail();
	void retriveNewEmail(Email *email);
	void printBox(BoxType boxType);
	Email* searchEmailUsingSubject(std::string userInput, BoxType boxType);						//needs boxType
	std::vector<Email*> searchEmailUsingSubjectReturnAll(std::string userInput, BoxType boxType);	//needs boxType
	Email* searchEmailByID(unsigned int userInput, BoxType boxType);			
	Email* searchEmailByPresenceOfAttachments(BoxType boxType);

	bool deleteEmail(unsigned int emailId, BoxType boxType); 
	bool deletedAllEmails(BoxType boxType);
	bool emptyDeletedEmails();
	std::stack<Email*, std::vector<Email*>>* getBoxType(BoxType boxType);

	void addContact(std::vector<User> allUsers);
	void addContact(User User);
	void removeContact(std::vector<User> allUsers, std::string name);
	std::map<std::string, std::string> searchContact(std::vector<User> allUsers, std::string name);
	
	//(==, !=, =, <<, and >>)
	bool operator>(const User& other);
	bool operator==(const User& other);
	bool operator!=(const User& other);

private:
	std::string name, password, emailAddress;
	std::stack<Email*, std::vector<Email*>> inbox, outbox, sentbox, deletedbox;
	int id, inboxSize;
	std::map<std::string, std::string> contactList;
};

