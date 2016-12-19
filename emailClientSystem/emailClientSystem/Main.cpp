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

void menu(User *user);
void openUserMenu(User *user);
void newEmail(User *user);
template <typename T>
void swap(T* pArray, int i, int j);
void selectionSort(User* pArray, int length);



int main()
{
	int length = 5;
	
	User user("Paddy", "paddyPassword", "paddy@gmail.com");
	populateEmails(user);

	
	menu(&user);

	system("pause");
	return 0;
}

template <typename T>
void swap(T* pArray, int i, int j)
{
	T temp = pArray[i];	pArray[i] = pArray[j]; 	pArray[j] = temp;
}

void selectionSort(User* pArray, int length)
{
	if (pArray == nullptr || length <= 0)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		int minPos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (pArray[minPos].getName() > pArray[j].getName())
				minPos = j;
		}
		if (minPos != i)
			swap(pArray, minPos, i);
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
		std::string address = j +"address@gmail.com";
		recipients.push_back(address);
		user.createNewEmail(Email(user.getEmailAddress(), recipients, subject, body));
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
		std::cout << "(7) Back" << std::endl;


		std::cin >> answer;
		switch (answer)
		{
		case 1:
			newEmail(user);
			break;

		case 2:
			check = false;
			break;

		case 3:
			check = false;
			break;

		case 4:
			check = false;
			break;

		case 5:
			check = false;
			break;

		case 6:
			check = false;
			break;

		case 7:
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
	std::getline(cin, subject);
	std::cin.ignore();

	std::cout << "Enter Body:\t";
	std::getline(cin, body);
	std::cin.ignore();

	bool check = true;
	while (check)
	{
		std::cout << "Any Attachments? [Y/N]";
		std::cin >> checkAttachment;
		if (checkAttachment == "Y")
		{
			int attachCount;
			cout << "How many Attachments?" << endl;
			cin >> attachCount;

			std::vector<Attachment> attachments;
			for (int i = 0; i < recCount; i++)
			{
				std::string fileName, fileSuffix;
				std::cout << "Enter File Name:\t";
				std::cin >> fileName;
				std::cout << "Enter File Suffix:\t";
				std::cin >> fileSuffix;
				attachments.push_back(Attachment(fileName, fileSuffix));
			}

			user->createNewEmail(Email(user->getEmailAddress(), recipients, subject, body, attachments));
			check = false;
		}
		else if (checkAttachment == "N")
		{
			user->createNewEmail(Email(user->getEmailAddress(), recipients, subject, body));
			check = false;
		}
		else
			std::cout << "Please enter either Y or N" << endl;
	}


	std::cout << "How many recipents?" << endl;
	std::cin >> recCount;

	for (int i = 0; i < recCount; i++)
	{
		std::cout << "Enter Recipient " << i << ":\t";
		std::cin >> recipient;

		recipients.push_back(recipient);
	}

}