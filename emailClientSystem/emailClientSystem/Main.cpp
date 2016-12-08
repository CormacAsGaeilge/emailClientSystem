#include <iostream>
#include "User.h"
#include "Email.h"
using namespace std;

void searchEmailUsingSubject(string userInput);

int main()
{
	User testUser("Paddy", "password1", "paddy@gmail.com");
	Email testEmail("paddy@gmail.com", "Test Subject", "Test Body");

	testEmail.print();

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