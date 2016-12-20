#include <iostream>
#include "User.h"
#include "Email.h"
#include "DynamicArray.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <cstdlib>
void populateEmails(User &user);
void deletEmail(User *user);
void deleteAllEmails(User *user);
void viewEmail(User *user);
void reset(User *user);
void searchBy(User *user);
void menu(User *user);
void openUserMenu(User *user);
void newEmail(User *user);
void sortMenu(User *user, BoxType boxType);


bool subjectGreaterThan(Email * e1, Email * e2)
{
	if (e1->getSubject() > e2->getSubject())
		return true;
	else
		return false;
}
bool bodyGreaterThan(Email * e1, Email * e2)
{
	if (e1->getSubject() >= e2->getSubject())
		return true;
	else
		return false;
}
bool recipientsGreaterThan(Email * e1, Email * e2)
{
	if (e1->getRecipients().size() >= e2->getRecipients().size())
		return true;
	else
		return false;
}
bool attachmentsGreaterThan(Email * e1, Email * e2)
{
	if (e1->getAttachments().size() >= e2->getAttachments().size())
		return true;
	else
		return false;
}

template <typename T>
void swap(std::vector<T*> vector, int i, int j);

template<typename T>
void selectionSort(std::vector<T*> vector, bool(*funct)(T*, T*), int length);

int main()
{
	int length = 5;
	
	User user("Paddy", "paddyPassword", "paddy@gmail.com");
	populateEmails(user);

	User test("Rani", "hello892ItsRani", "paddy@gmail.com");
	std::cout << test.getPassword() << std::endl;
	std::vector<User> userVector;
	userVector.push_back(test);
	for (User u : userVector)
		std::cout << u << std::endl;
	menu(&user);

	system("pause");
	return 0;
}

template <typename T>
void swap(std::vector<T*> vector, int i, int j)
{
	T* temp = vector[i];	vector[i] = vector[j]; 	vector[j] = temp;
}

template<typename T>
void selectionSort(std::vector<T*> vector, bool(*funct)(T*, T*), int length)
{
	if (length <= 0)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		int minPos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (funct)
				minPos = j;
		}
		if (minPos != i)
			swap(vector, minPos, i);
	}
}
void populateEmails(User &user)
{
	std::vector<std::string> recipients; 
	std::string subject = "email subject line", body = "email content body";
	int randomUser = 0; //needs to be set to random
	for (int j = 0; j < 10; j++)
	{
		//randomise body and subject too
		std::string address ="address@gmail.com";
		recipients.push_back(address);
		user.createNewEmail(new Email(user.getEmailAddress(), recipients, subject, body));
		recipients.pop_back();
	}
}

void menu(User *user)
{
	bool check = true;
	while (check)
	{
		int answer;

		std::cout << "(1) Open User" << std::endl;
		std::cout << "(2) Exit" << std::endl;

		std::cin >> answer;
		switch (answer)
		{
		case 1:
			openUserMenu(user);
			break;

		case 2:
			std::cout << "Goodbye" << std::endl;
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}
	}
}


void openUserMenu(User *user)
{
	bool check = true;
	std::string password = user->getPassword();
	int passwordLength = password.length();
	std::string hiddenPassword = "*";
	for (int i = 0; i < passwordLength; i++)
		hiddenPassword += "*";
	std::cout <<
		"USER:\t" << user->getName() <<
		"\nEMAIL ADDRESS:\t" << user->getEmailAddress() <<
		"\nPASSWORD:\t" << hiddenPassword << std::endl;

	while (check)
	{
		User currentUser;
		int answer;
		std::cout << "(1) New" << std::endl;
		std::cout << "(2) View" << std::endl;
		std::cout << "(3) Delete" << std::endl;
		std::cout << "(4) Delete All" << std::endl;
		std::cout << "(5) Search By" << std::endl;
		std::cout << "(6) RESET" << std::endl;
		std::cout << "(7) Back"	<< std::endl;

		std::cin >> answer;
		switch (answer)
		{
		case 1:
			newEmail(user);
			break;

		case 2:
			viewEmail(user);
			break;

		case 3:
			deletEmail(user);
			break;

		case 4:
			deleteAllEmails(user);
			break;

		case 5:
			searchBy(user);
			break;

		case 6:
			reset(user);
			break;

		case 7:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}
	}
}

void viewEmail(User *user)
{
	bool check = true;

	while (check)
	{
		User currentUser;
		int answer;
		std::cout << "(1) View Inbox" << std::endl;
		std::cout << "(2) View Outbox" << std::endl;
		std::cout << "(3) View Sentbox" << std::endl;
		std::cout << "(4) View Deleted Emails" << std::endl;
		std::cout << "(5) Sort Inbox" << std::endl;
		std::cout << "(6) Sort Outbox" << std::endl;
		std::cout << "(7) Sort SentBox" << std::endl;
		std::cout << "(8) Back" << std::endl;
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			user->printBox(InboxType);
			break;

		case 2:
			user->printBox(OutboxType);
			break;

		case 3:
			user->printBox(SentboxType);
			break;

		case 4:
			user->printBox(DeletedboxType);
			break;
		case 5:
			sortMenu(user, InboxType);
			break;
		case 6:
			sortMenu(user, OutboxType);
			break;
		case 7:
			sortMenu(user, SentboxType);
			break;

		case 8:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}


	}
}

void deletEmail(User* user)
{
	bool check = true;
	int userInput;	

	while (check)
	{
		User currentUser;
		int answer;
		std::cout << "(1) Delete From Inbox" << std::endl;
		std::cout << "(2) Delete From Outbox" << std::endl;
		std::cout << "(3) Delete From Sentbox" << std::endl;
		std::cout << "(4) Delete From Deleted Emails" << std::endl;
		std::cout << "(5) Back" << std::endl;
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			std::cout << "Please enter a valid ID: " << std::endl;
			std::cin >> userInput;
			user->deleteEmail(userInput, InboxType);
			break;

		case 2:
			std::cout << "Please enter a valid ID: " << std::endl;
			std::cin >> userInput;
			user->deleteEmail(userInput, OutboxType);
			break;

		case 3:
			std::cout << "Please enter a valid ID: " << std::endl;
			std::cin >> userInput;
			user->deleteEmail(userInput, SentboxType);
			break;

		case 4:
			std::cout << "Please enter a valid ID: " << std::endl;
			std::cin >> userInput;
			user->deleteEmail(userInput, DeletedboxType);
			break;

		case 5:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}
	}
}

void deleteAllEmails(User *user)
{
	bool check = true;
	int userInput;
	while (check)
	{
		User currentUser;
		int answer;
		std::cout << "(1) Delete All From Inbox" << std::endl;
		std::cout << "(2) Delete All From Outbox" << std::endl;
		std::cout << "(3) Delete All From Sentbox" << std::endl;
		std::cout << "(4) Delete All From Deleted Emails" << std::endl;
		std::cout << "(5) Back" << std::endl;
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			std::cin >> userInput;
			user->deletedAllEmails(InboxType);
			break;

		case 2:
			std::cin >> userInput;
			user->deletedAllEmails(OutboxType);
			break;

		case 3:
			std::cin >> userInput;
			user->deletedAllEmails(SentboxType);
			break;

		case 4:
			std::cin >> userInput;
			user->deletedAllEmails(DeletedboxType);
			break;

		case 5:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}
	}
}

void searchBy(User * user)
{
	std::cout << "________________Search By________________" << std::endl;
	bool check = true;
	std::string userInput;
	int userId;
	BoxType boxType;


	std::cout << "Choose Which Inbox to search in:\n" << std::endl;
	while (check)
	{
		User currentUser;
		int answer;
		std::cout << "(1) Inbox" << std::endl;
		std::cout << "(2) Outbox" << std::endl;
		std::cout << "(3) Sentbox" << std::endl;
		std::cout << "(4) Deleted Emails" << std::endl;
		std::cout << "(5) Back" << std::endl;
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			boxType = InboxType;
			std::cout << "________________INBOX________________" << std::endl;
			check = false;
			break;

		case 2:
			boxType = OutboxType;
			std::cout << "________________OUTBOX________________" << std::endl;
			check = false;
			break;

		case 3:
			boxType = SentboxType;
			std::cout << "________________SENTBOX________________" << std::endl;
			check = false;
			break;

		case 4:
			boxType = DeletedboxType;
			std::cout << "________________DELETEDBOX________________" << std::endl;
			check = false;
			break;

		case 5:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}

	}

	check = true;

	while (check)
	{
		User currentUser;
		int answer;
		std::vector<Email*> temp;
		std::cout << "(1) Search by id" << std::endl;
		std::cout << "(2) Search by subject" << std::endl;
		std::cout << "(3) Search by presence of attachments" << std::endl;
		std::cout << "(4) Back" << std::endl;
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			std::cin >> userId;
			std::cout << user->searchEmailByID(userId, boxType);
			break;

		case 2:
			std::cin >> userInput;
			temp = user->searchEmailUsingSubjectReturnAll(userInput, boxType);
			for (int i = 0; i < temp.size(); i++)
				std::cout << temp[i];
			break;

		case 3:
			std::cout << user->searchEmailByPresenceOfAttachments(boxType);
			break;

		case 4:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}
	}
}

void newEmail(User *user)
{
	int recCount;
	std::vector<std::string> recipients;
	std::string recipient, subject, body, checkAttachment;
	std::cout << "________________NEW EMAIL________________" << std::endl;
	std::cout << "Enter Subject:\t";
	std::getline(std::cin, subject);
	std::cin.ignore();

	std::cout << "Enter Body:\t";
	std::getline(std::cin, body);
	std::cin.ignore();

	bool check = true;
	while (check)
	{
		std::cout << "Any Attachments? [Y/N]";
		std::cin >> checkAttachment;
		if (checkAttachment == "Y")
		{
			int attachCount;
			std::cout << "How many Attachments?" << std::endl;
			std::cin >> attachCount;

			std::vector<Attachment> attachments;
			for (int i = 0; i < attachCount; i++)
			{
				std::string fileName, fileSuffix;
				std::cout << "Enter File Name:\t";
				std::cin >> fileName;
				std::cout << "Enter File Suffix:\t";
				std::cin >> fileSuffix;
				attachments.push_back(Attachment(fileName, fileSuffix));
			}

			user->createNewEmail(new Email(user->getEmailAddress(), recipients, subject, body, attachments));
			check = false;
		}
		else if (checkAttachment == "N")
		{
			user->createNewEmail(new Email(user->getEmailAddress(), recipients, subject, body));
			check = false;
		}
		else
			std::cout << "Please enter either Y or N" << std::endl;
	}


	std::cout << "How many recipents?" << std::endl;
	std::cin >> recCount;

	for (int i = 0; i < recCount; i++)
	{
		std::cout << "Enter Recipient " << i << ":\t";
		std::cin >> recipient;

		recipients.push_back(recipient);
	}

}


void reset(User *user)
{
	bool check = true;
	while (check)
	{
		std::string answer;
		std::cout << "Do you really want to reset everything? [Y/N]" << std::endl;
		std::cin >> answer;

		if (answer == "Y")
		{
			//RESET EVERTHING
			check = false;
		}
		else if (answer == "N")
		{
			check = false;
		}
		else
			std::cout << "Please enter either Y or N" << std::endl;
	}
}

void sortMenu(User *user, BoxType boxType)
{
	bool check = true;
	std::stack<Email*, std::vector<Email*>>* box = user->getBoxType(boxType);

	while (check)
	{
		User currentUser;
		int answer;
		std::vector<Email*> temp;
		std::cout << "(1) Sort by subject" << std::endl;
		std::cout << "(2) Sort by body" << std::endl;
		std::cout << "(3) Sort by number of recipients" << std::endl;
		std::cout << "(4) Sort by number of attachments" << std::endl;
		std::cout << "(5) Back" << std::endl;
		std::cin >> answer;
		bool(*pFunc)(Email*, Email*);
		pFunc = &subjectGreaterThan;
		std::vector<Email*> vec;
		for (int i = 0; i < box->size(); i++)
		{
			vec.push_back(box->top());
			box->pop();
		}

		switch (answer)
		{
		case 1:
			
			pFunc = &subjectGreaterThan;
			std::cout << "Sorted by Subject.\n";
			break;

		case 2:
			pFunc = &bodyGreaterThan;
			std::cout << "Sorted by Body.\n";
			break;

		case 3:
			pFunc = &recipientsGreaterThan;
			std::cout << "Sorted by number of Recipients.\n";
			break;

		case 4:
			pFunc = &attachmentsGreaterThan;
			std::cout << "Sorted by number of Attachments.\n";
			break;

		case 5:
			check = false;
			break;

		default:
			std::cout << "Bad choice! Please try again.\n";
		}

		selectionSort(vec, pFunc, box->size());
		for (int i = 0; i < box->size(); i++)
		{
			box->push(vec[i]);
		}
	}
}