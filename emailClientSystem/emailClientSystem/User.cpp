#include "User.h"
#include "Email.h"
#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <exception>
#include <regex>

User::User():User("defaultName","defaoultPassword","defaultEmailAddress")
{
}

User::User(std::string name, std::string password, std::string emailAddress)
{
	setID(count++);
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
		User::name = "default_name";
	else
		User::name = name;  //Length >= 8 
		
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

void User::sendEmail()
{
	User::printBox(OutboxType);
}
void User::retriveNewEmail(Email email)
{
	User::inbox.push(email);
}

void User::printBox(BoxType boxType)
{
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	std::cout << "_____________________" << boxType << "_____________________" << std::endl;
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

//Search EMAIL By Subject
Email User::searchEmailUsingSubject(std::string userInput, BoxType boxType)
{
	Email email;
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	while (size > 0)
	{
		if (box->top().getSubject() == userInput)
			email = box->top();
		tempBox.push(box->top());
		box->pop();
		size = box->size();
	}

	//add emails back to stack
	size = tempBox.size();
	while (size > 0)
	{
		box->push(tempBox.top());	//add back to the box
		tempBox.pop();				//remove from temp box
		size = tempBox.size();		//get size for while check
	}
	//loop through subjects 
	//match subject

	return email;
}

std::vector<Email> User::searchEmailUsingSubjectReturnAll(std::string userInput, BoxType boxType)
{
	
	std::vector<Email> allEmails;
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType), tempBox;

	size_t size = User::inbox.size();
	while (size > 0)
	{
		if (box->top().getSubject() == userInput)
			allEmails.push_back(box->top());
		tempBox.push(box->top());
		box->pop();
		size = box->size();
	}

	//add emails back to stack
	size = tempBox.size();
	while (size > 0)
	{
		box->push(tempBox.top());	//add back to the box
		tempBox.pop();				//remove from temp box
		size = tempBox.size();		//get size for while check
	}

	//loop through subjects 
	//match subject

	return allEmails;
}
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

bool User::deletedAllEmails(BoxType boxType)
{
	std::stack<Email, std::vector<Email>>* box = User::getBoxType(boxType);
	size_t size = box->size();
	size_t checkForChange = size;	
	while (size > 0)
	{	
		box->pop();
		size = box->size();
	}
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
			newMap.insert(std::pair<std::string, std::string>(u.getName(), u.getEmailAddress()));
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


std::ostream& operator<<(ostream & outStream, const User & user)
{
	outStream << "Name:\t" << user.name << "\nEmail:\t" << user.emailAddress << "\n";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, User & user)
{
	string str;
	inStream >> str;
	return inStream;
}

bool User::operator>(const User &other)
{
	if (User::name > other.name)
		return true;
	else
		return false;
}

bool User::operator==(const User & other)
{
	if (User::name == other.name)
		return true;
	else
		return false;
}

bool User::operator!=(const User & other)
{
	if (User::name != other.name)
		return true;
	else
		return false;
}
