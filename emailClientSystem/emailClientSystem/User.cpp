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

//Search EMAIL By Subject
Email User::searchEmailUsingSubject(std::string userInput)
{
	Email email;

	email.getSubject();

	//loop through subjects 
	//match subject

	return std::cout << email.getSubject << std::endl;
}