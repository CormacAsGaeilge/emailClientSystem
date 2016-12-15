#include <iostream>
#include "User.h"
#include "Email.h"
#include "DynamicArray.h"
#include <vector>

void populateUsers(DynamicArray<User> &allUsers);
void populateEmails(DynamicArray<User> &allUsers);
void demoReadAllInbox(DynamicArray<User> &allUsers);

int main()
{
	DynamicArray<User> allUsers(5);
	populateUsers(allUsers);

	populateEmails(allUsers);

	demoReadAllInbox(allUsers);


	system("pause");
	return 0;
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
	std::string recipient, subject = "email subject line", body = "email content body";
	int randomUser = 0; //needs to be set to random
	for (int i = 0; i < allUsers.Count(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//randomise body and subject too
			recipient = allUsers[randomUser].getEmailAddress();
			allUsers[i].createNewEmail(Email(id, recipient, subject, body));
			id++;
		}
	}
}

void populateUsers(DynamicArray<User> &allUsers)
{

	std::string name = "Bob", password = "pa55w0rd", emailAddress = "bob@gmail.com";
	User u1(name, password, emailAddress);
    allUsers.Add(u1,0);

	name = "Paddy", password = "password1", emailAddress = "paddy@gmail.com";
	User u2(name, password, emailAddress);
	allUsers.Add(u2,1);

	name = "Cormac", password = "wordpass", emailAddress = "cormac@gmail.com";
	User u3(name, password, emailAddress);
	allUsers.Add(u3,2);

	name = "Fred", password = "fredpass", emailAddress = "fred@gmail.com";
	User u4(name, password, emailAddress);
	allUsers.Add(u4,3);

	name = "Rani", password = "paddy1", emailAddress = "rani@gmail.com";
	User u5(name, password, emailAddress);
	allUsers.Add(u5,4);
}

