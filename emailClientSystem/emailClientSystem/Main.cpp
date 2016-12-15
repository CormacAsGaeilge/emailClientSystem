#include <iostream>
#include "User.h"
#include "Email.h"
#include "DynamicArray.h"
#include <vector>

void populateUsers(DynamicArray<User> *allUsers);

int main()
{
	DynamicArray<User> allUsers(10);
	populateUsers(&allUsers);

	std::string recipient, subject = "email subject line", body = "email content body";
	int randomUser = 0; //needs to be set to random
	for (int i = 0; i < allUsers.Count(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//randomise body and subject too
			recipient = allUsers[randomUser].getEmailAddress();
			Email newEmail(recipient, subject, body);
			allUsers[i].createNewEmail(newEmail);
		}
	}

	for (int i = 0; i < allUsers.Count(); i++)
	{
		allUsers[i].printOutbox();
	}
	system("pause");
	return 0;
}

void populateUsers(DynamicArray<User> *allUsers)
{

	std::string name = "Bob", password = "pa55w0rd", emailAddress = "bob@gmail.com";
	User u1(name, password, emailAddress);
    allUsers->AddLast(u1);

	name = "Paddy", password = "password1", emailAddress = "paddy@gmail.com";
	User u2(name, password, emailAddress);
	allUsers->AddLast(u2);

	name = "Cormac", password = "wordpass", emailAddress = "cormac@gmail.com";
	User u3(name, password, emailAddress);
	allUsers->AddLast(u3);

	name = "Fred", password = "fredpass", emailAddress = "fred@gmail.com";
	User u4(name, password, emailAddress);
	allUsers->AddLast(u4);

	name = "Rani", password = "paddy1", emailAddress = "rani@gmail.com";
	User u5(name, password, emailAddress);
	allUsers->AddLast(u5);
}

