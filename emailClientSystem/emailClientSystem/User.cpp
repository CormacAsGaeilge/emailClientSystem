#include "User.h"
#include "Email.h"
#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <regex>


User::User():User("defaultName","defaoultPassword","defaultEmailAddress")
{
}

User::User(std::string name, std::string password, std::string emailAddress)
{
	setName(name);
	setPassword(password);
	setEmailAddress(emailAddress);
	inboxSize = 0;
}

User::~User()
{
}

//SETTERS WILL BE RE_WRITTEN INTO SIMPLE FORM
void User::setName(std::string name)
{
	if (name.length() >= 8)
		User::name = name;  //Length >= 8 
	else
		User::name = "default_name";
}

//NOT TESTED 
//LONG AND NEEDS CLEANING UP 
//ILL GET BACK TO THIS 
void User::setPassword(std::string password)
{
	//Length >= 8 characters;
	//Must contain minimum of 1 number and 1 letter(non - case senstive).
	char *y = new char[password.length() + 1];
	std::string validation;
	int valid1 = 0;
	int valid2 = 0;
	int valid3 = 0;
	if (password.length() >= 8)
	{
		for (int i = 0; i <= password.length(); i++)
		{
			if (*y >= 65 && *y <= 90)
				valid1++;
			if (*y >= 97 && *y <= 122)
				valid2++;
			if (*y >= 48 && *y <= 57)
				valid3++;
		}
	}

	if (valid1 > 0 && valid2 > 0 && valid3 > 0)
		User::password = password;
	else
		User::password = "default_password";
}


void User::setEmailAddress(std::string emailAddress)
{
	//Valid email (regex)
	std::string regex = "\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}\b";
	User::emailAddress = emailAddress;
}
	 

void User::createNewEmail(Email email)
{
	User::outbox.push(email);
}

void User::retriveNewEmail(Email email)
{
	User::inbox.push(email);
}

void User::printBox(BoxType boxType)
{
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	while (size > 0)
	{
		box->top().print();
		std::cout << "_________________________________________" << std::endl;
		tempBox.push(box->top());
		box->pop();
		size = box->size();
	}

	std::cout << "__________________end___________________" << std::endl;

	size = tempBox.size();
	while (size > 0)
	{
		box->push(tempBox.top());
		tempBox.pop();
		size = tempBox.size();
	}

}
/* No Longer Needed*/
/*
void User::printInbox()
{
	std::stack<Email, std::vector<Email>> tempInbox;
	size_t size = User::inbox.size();
	while (size > 0)
	{
		User::inbox.top().print();
		std::cout << "_________________________________________" << std::endl;
		tempInbox.push(User::inbox.top());
		User::inbox.pop();
		size = User::inbox.size();
	}

	std::cout << "__________________end___________________" << std::endl;

	size = tempInbox.size();
	while (size > 0)
	{
		User::inbox.push(tempInbox.top());
		tempInbox.pop();
		size = tempInbox.size();
	}

}

void User::printOutbox()
{
	std::stack<Email, std::vector<Email>> tempOutbox;
	size_t size = User::outbox.size();
	while (size > 0)
	{
		User::outbox.top().print();
		std::cout << "_________________________________________" << std::endl;
		tempOutbox.push(User::outbox.top());
		User::outbox.pop();
		size = User::outbox.size();
	}

	std::cout << "__________________end___________________" << std::endl;

	size = tempOutbox.size();
	while (size > 0)
	{
		User::outbox.push(tempOutbox.top());
		tempOutbox.pop();
		size = tempOutbox.size();
	}
}
void User::printSentbox()
{
	std::stack<Email, std::vector<Email>> tempSentbox;
	size_t size = User::sentbox.size();
	while (size > 0)
	{
		User::sentbox.top().print();
		std::cout << "_________________________________________" << std::endl;
		tempSentbox.push(User::sentbox.top());
		User::sentbox.pop();
		size = User::sentbox.size();
	}

	std::cout << "__________________end___________________" << std::endl;

	size = tempSentbox.size();
	while (size > 0)
	{
		User::sentbox.push(tempSentbox.top());
		tempSentbox.pop();
		size = tempSentbox.size();
	}
}
*/

//Search EMAIL By Subject
Email User::searchEmailUsingSubject(std::string userInput)
{
	Email email;
	std::stack<Email, std::vector<Email>> tempInbox;
	size_t size = User::inbox.size();
	while (size > 0)
	{
		if (User::inbox.top().getSubject() == userInput)
			email = inbox.top();
		tempInbox.push(User::inbox.top());
		User::inbox.pop();
		size = User::inbox.size();
	}

	//loop through subjects 
	//match subject

	return email;
}

std::vector<Email> User::searchEmailUsingSubjectReturnAll(std::string userInput)
{
	
	std::vector<Email> allEmails;

	std::stack<Email, std::vector<Email>> tempInbox;


	size_t size = User::inbox.size();
	while (size > 0)
	{
		if (User::inbox.top().getSubject() == userInput)
			allEmails.push_back(User::inbox.top());
		tempInbox.push(User::inbox.top());
		User::inbox.pop();
		size = User::inbox.size();
	}


	//loop through subjects 
	//match subject

	return allEmails;
}
//PADDY!!!!!!! - Make sure to reset the stack anytime you iterate through it. Otherwise it'll be deleted
//Look below how to use a temporary stack to reset the original stacks
Email User::searchEmailByID(unsigned int userInput, BoxType boxType)
{
	Email email;
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	//remove emails from stack
	while (size > 0)
	{
		if (box->top().getId() == userInput)
			email = box->top();
		tempBox.push(box->top());	//add to the temp box
		box->pop();					//remove from the box
		size = box->size();			//get size for while check
	}

	//add emails back to stack
	size = tempBox.size();
	while (size > 0)
	{
		box->push(tempBox.top());	//add back to the box
		tempBox.pop();				//remove from temp box
		size = tempBox.size();		//get size for while check
	}

	return email; //returns email with the requested id
}

bool User::deleteEmail(unsigned int emailId, BoxType boxType)
{
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	size_t checkForChange = size;			//set to original size
	while (size > 0)
	{
		if (box->top().getId() != emailId)	//If not the email to delete
			tempBox.push(box->top());		//Add to the tempBox
		box->pop();					
		size = box->size();			
	}
											//Email to delete will not be added back into box
	size = tempBox.size();
	while (size > 0)
	{
		box->push(tempBox.top());	
		tempBox.pop();				
		size = tempBox.size();		
	}

	if (checkForChange == box->size())		//if email has been deleted box size will be one less
		return false;
	else
		return true;
}

//Empty's deletedbox 
bool User::emptyDeletedEmails()
{
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(DeletedboxType);
	size_t size = box->size();
	while (size > 0)
	{
		box->pop();
		size = box->size();
	}
	return true;
}
//TO DO - MAKE GENERIC
void User::addContact(std::vector<User> allUsers)
{
	int length = allUsers.size();
	for(int i = 0; i < length; i++)
		User::addContact(allUsers[i]);
}

void User::addContact(User user)
{
	contactList.insert(std::pair<std::string,std::string>(User::getName(), User::getEmailAddress()));
}


//this functiom should erase by Key
//First draft erase
void User::removeContact(std::vector<User> allUsers, std::string name)
{
	for(User u : allUsers)
		if (name == u.getName())
		{
			contactList.erase(u.getName());
		}
}

//search for a contact
//should probabnly search through the contact list
std::map<std::string, std::string> User::searchContact(std::vector<User> allUsers, std::string name)
{
	std::map<std::string, std::string> newMap;
	for (User u : allUsers)
		if (name == u.getName())
		{
			newMap.insert(u.getName(), u.getEmailAddress());
		}

	return newMap;
}

//used for choosing which box to make changes to
std::stack<Email, std::vector<Email>>* User::getBoxType(BoxType boxType)
{
	if (boxType == InboxType)
		return &inbox;
	else if (boxType == OutboxType)
		return &outbox;
	else if (boxType == SentboxType)
		return &sentbox;
	else
		return &deletedbox;
}