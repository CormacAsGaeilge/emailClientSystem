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
void populateUsers(DynamicArray<User> &allUsers);
void populateEmails(DynamicArray<User> &allUsers);
void demoReadAllInbox(DynamicArray<User> &allUsers);
void menu();

template <typename T>
void selectionSort(DynamicArray<T> *pArray, int length);
template <typename T>
void selectionSort(std::vector<T> *pArray, int length);


template <typename T>
void swap(T* pArray, int i, int j);

int main()
{
	DynamicArray<User> allUsers(5);
	populateUsers(allUsers);

	//populateEmails(allUsers);

	//demoReadAllInbox(allUsers);

	//User testUser("Dan", "123456", "dan@gmail.com");
	//testUser.addContact(allUsers[1]);

	constexpr int N = 4;

	allUsers.Print();
	//selectionSort(&allUsers, N);
	//allUsers.Print();
	//menu();

	system("pause");
	return 0;
}

template <typename T>
void swap(T* pArray, int i, int j)
{
	T temp = pArray[i];	
	pArray[i] = pArray[j]; 	
	pArray[j] = temp;
}

template <typename T>
void selectionSort(DynamicArray<T> *pArray, int length)
{
	if (pArray == nullptr || length <= 0)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		int minPos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (pArray[minPos] > pArray[j])
			{
				minPos = j;
			}
		}
		if (minPos != i) //found a smaller value!
			swap(pArray, minPos, i);
	}
}
template <typename T>
void selectionSort(std::vector<T> *pArray, int length)
{
	if (pArray == nullptr || length <= 0)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		int minPos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (pArray[minPos] > pArray[j])
			{
				minPos = j;
			}
		}
		if (minPos != i) //found a smaller value!
			swap(pArray, minPos, i);
	}
}

void demoReadAllInbox(DynamicArray<User> &allUsers)
{
	for (int i = 0; i < allUsers.Count(); i++)
	{
		allUsers[i].printBox(OutboxType);
	}
}

void populateEmails(DynamicArray<User> &allUsers)
{
	unsigned int id = 1;
	std::vector<std::string> recipients; 
	std::string subject = "email subject line", body = "email content body";
	int randomUser = 0; //needs to be set to random
	for (int i = 0; i < allUsers.Count(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//randomise body and subject too
			recipients.push_back(allUsers[randomUser].getEmailAddress());
			allUsers[i].createNewEmail(Email(id, allUsers[i].getEmailAddress(), recipients, subject, body));
			id++;
			recipients.pop_back();
		}
	}
}

void populateUsers(DynamicArray<User> &allUsers)
{

	allUsers.Initialize();
	std::string name = "Bob", password = "pa55w0rd", emailAddress = "bob@gmail.com";
	User u1(name, password, emailAddress);
	allUsers.Add(u1, 0);

	name = "Paddy", password = "password1", emailAddress = "paddy@gmail.com";
	User u2(name, password, emailAddress);
	allUsers.Add(u2, 1);

	name = "Cormac", password = "wordpass", emailAddress = "cormac@gmail.com";
	User u3(name, password, emailAddress);
	allUsers.Add(u3, 2);

	name = "Fred", password = "fredpass", emailAddress = "fred@gmail.com";
	User u4(name, password, emailAddress);
	allUsers.Add(u4, 3);

	name = "Rani", password = "paddy1", emailAddress = "rani@gmail.com";
	User u5(name, password, emailAddress);
	allUsers.Add(u5, 4);
}

void menu()
{
	int answer;

	std::cout << "(1) Inbox" << std::endl;
	std::cout << "(2) Outbox" << std::endl;
	std::cout << "(3) Sent" << std::endl;
	std::cout << "(4) Deleted" << std::endl;


	
	std::cin >> answer;
	switch (answer)
	{
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	default:
		std::cout << "Bad choice! Please try again later.\n";
	}

}

