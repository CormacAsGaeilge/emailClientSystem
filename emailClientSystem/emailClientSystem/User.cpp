#include "User.h"
#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <exception>
#include <regex>


int User::count = 0;

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

//De-Constructer
//Resetting All Emails
User::~User()
{
	size_t size = User::inbox.size();
	while (size > 0)
	{
		inbox.top() = nullptr;
		inbox.pop();
		size--;
	}

	size = User::outbox.size();
	while (size > 0)
	{
		outbox.top() = nullptr;
		outbox.pop();
		size--;
	}

	size = User::sentbox.size();
	while (size > 0)
	{
		sentbox.top() = nullptr;
		sentbox.pop();
		size--;
	}

	size = User::deletedbox.size();
	while (size > 0)
	{
		deletedbox.top() = nullptr;
		deletedbox.pop();
		size--;
	}

}

//Setter for name
void User::setName(std::string name)
{
	//Length must be <= 8 characters
	User::name = (name.length() <= 8) ? name : "default_name";		
}

//HOW Paddy's brain works
//Password Validation
void User::setPassword(std::string password)
{

	//Length >= 8 characters;
	//Must contain minimum of 1 number and 1 letter(non - case senstive).
	char *y = new char[password.length() + 1]; //setting up a Character Array
	for (int i = 0; i < password.length(); i++) 
	{
		y[i] = password[i];   //population character array
	}
	//setting up a vaviable for each requirenment 
	std::string validation;
	int valid1 = 0;
	int valid2 = 0;
	int valid3 = 0;
	if (password.length() >= 8) // Requrement #1 Must be Greater than or equal 8
	{
		for (int i = 0; i <= password.length(); i++) //looping through each character in the array to check type;
		{
			if (y[i] >= 65 && y[i] <= 90) // If the character is between numbers its UPPERCASE
				valid1++;
			if (y[i] >= 97 && y[i] <= 122) //LOWERCASE
				valid2++;
			if (y[i] >= 48 && y[i] <= 57)//NUMBERS
				valid3++;
		}
	}
		if (valid1 > 0 && valid2 > 0 && valid3 > 0) //Must have at least one of each to be a valid password
			User::password = password;
		else
			User::password = "default_password";
}

// http://stackoverflow.com/questions/26965672/using-regex-for-input-validation
//Use this method to create Regex validation
bool regexValidate(std::string expression, std::string email)
{
	std::regex ex(expression); //simplify expresssion 
	if (regex_match(email, ex)) { //checks if email matches expression
		return true;
	}
	else
		return false;
}

//Email validation
void User::setEmailAddress(std::string emailAddress)
{
	//Valid email (regex)
	std::string regex = "[\\w]+@[\\w]+.[\\w]{2,3}"; //Simple Email Regex
	if (regexValidate(regex, emailAddress)) //If match is true then ist valid
		User::emailAddress = emailAddress;
	else
		User::emailAddress = "deafault_email";
}
	 

void User::createNewEmail(Email *email)
{
	User::outbox.push(email);
}

void User::sendEmail()
{
	User::printBox(OutboxType);
}
void User::retriveNewEmail(Email *email)
{
	User::inbox.push(email);
}

void User::printBox(BoxType boxType)
{
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	std::cout << "_____________________" << boxType << "_____________________" << std::endl;
	while (size > 0)
	{
		box->top()->print();
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
Email* User::searchEmailUsingSubject(std::string userInput, BoxType boxType)
{
	Email *email = nullptr;
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	while (size > 0)
	{
		if (box->top()->getSubject() == userInput)
			Email *email = box->top();
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

std::vector<Email*> User::searchEmailUsingSubjectReturnAll(std::string userInput, BoxType boxType)
{
	
	std::vector<Email*> allEmails;
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType), tempBox;

	size_t size = User::inbox.size();
	while (size > 0)
	{
		if (box->top()->getSubject() == userInput)
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
Email* User::searchEmailByID(unsigned int userInput, BoxType boxType)
{
	Email *email = nullptr;
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	//remove emails from stack
	while (size > 0)
	{
		if (box->top()->getId() == userInput)
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

Email * User::searchEmailByPresenceOfAttachments(BoxType boxType)
{
	Email *email = nullptr;
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	//remove emails from stack
	while (size > 0)
	{
		if (box->top()->getAttachments().size() > 0)
			email = box->top();
		tempBox.push(box->top());
		box->pop();
		size = box->size();
	}
	size = tempBox.size();
	while (size > 0)
	{
		box->push(tempBox.top());
		tempBox.pop();
		size = tempBox.size();
	}

	return email;
}

bool User::deleteEmail(unsigned int emailId, BoxType boxType)
{
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType), tempBox;

	size_t size = box->size();
	size_t checkForChange = size;			//set to original size
	while (size > 0)
	{
		if (box->top()->getId() != emailId)	//If not the email to delete
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
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(boxType);
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
	std::stack<Email*, std::vector<Email*>>* box = User::getBoxType(DeletedboxType);
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
std::stack<Email*, std::vector<Email*>>* User::getBoxType(BoxType boxType)
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


std::ostream& operator<<(std::ostream & outStream, const User & user)
{
	outStream << "Name:\t" << user.name << "\nEmail:\t" << user.emailAddress << "\n";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, User & user)
{
	std::string str;
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
