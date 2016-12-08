#include "User.h"
#include "Email.h"


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