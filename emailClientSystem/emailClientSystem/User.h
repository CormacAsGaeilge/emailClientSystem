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
	void createNewEmail(Email email);
	void retriveNewEmail(Email email);
	void printBox(BoxType boxType);
	/*NO LONGER NEEDED*/
	/*void printInbox();
	void printOutbox();
	void printSentbox();*/
	Email searchEmailUsingSubject(std::string userInput);						//needs boxType
	std::vector<Email> searchEmailUsingSubjectReturnAll(std::string userInput);	//needs boxType
	Email searchEmailByID(unsigned int userInput, BoxType boxType);			
	
	bool deleteEmail(unsigned int emailId, BoxType boxType); 
	bool emptyDeletedEmails();
	std::stack<Email, std::vector<Email>>* getBoxType(BoxType boxType);
	//readEmail
	//markAsUnRead
	//viewContacts
	//AddToContacts
	void addContact();
	//RemoveFromContacts
	//CreateNewEmail - choose contact - create email object
	//SendEmail -  "send" to contact
	//deleteEmail
	//deleteAllEmails
	//searchBy date
	//searchBy subject
	//searchBy presence of attachment
	//SORT Quick sort3, shell



	//C++11 features ifOnce, ifNone, ifAll

private:
	std::string name, password, emailAddress;
	std::stack<Email, std::vector<Email>> inbox, outbox, sentbox, deletedbox;
	int inboxSize;
	std::map<std::string, std::string> contactList;
};

