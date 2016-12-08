#include "User.h"
#include "Email.h"
#include <string>


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

void User::createNewEmail(Email email)
{
	User::outbox.push(email);
}

void User::retriveNewEmail(Email email)
{
	User::inbox.push(email);
}

void User::printInbox()
{
	std::stack<Email, std::vector<Email>> tempInbox;
	size_t size = User::inbox.size();
	while( size > 0)
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