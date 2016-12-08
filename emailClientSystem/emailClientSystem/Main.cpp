#include <iostream>
#include "User.h"
#include "Email.h"
using namespace std;

void searchEmailUsingSubject(string userInput);

int main()
{
	User testUser("Paddy", "password1", "paddy@gmail.com");
	Email testEmail1("paddy@gmail.com", "Rani", "Test Body");
	testUser.retriveNewEmail(testEmail1);

	Email testEmail2("cormac@gmail.com", "Numbers", "Test Body");
	testUser.retriveNewEmail(testEmail2);

	Email testEmail3("charlie@gmail.com", "Graphics", "Test Body");
	testUser.retriveNewEmail(testEmail3);

	Email testEmail4("niall@gmail.com", "Code", "Test Body");
	testUser.retriveNewEmail(testEmail4);


	testUser.printInbox();
	cout << "BREAKLINE" <<endl;
	testUser.printInbox();
	system("pause");
	return 0;
}

//Search EMAIL By Subject
void searchEmailUsingSubject(string userInput)
{
	//get All subjects
	//Email::getSubject();
	//loop through subjects 
	//match subject
	//return 
}