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


bool User::emptyDeletedEmails()
{
	return false; //Not yet implemented
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