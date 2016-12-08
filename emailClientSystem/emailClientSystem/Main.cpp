#include <iostream>
#include "User.h"
#include "Email.h"


int main()
{
	User testUser("Paddy", "password1", "paddy@gmail.com");
	Email testEmail1("paddy@gmail.com", "Rani", "Test Body");
	testUser.retriveNewEmail(testEmail1);

	Email testEmail2("cormac@gmail.com", "Numbers", "Test Body");
	testUser.retriveNewEmail(testEmail2);

	testUser.searchEmailUsingSubject("Paddy");

	Email testEmail3("charlie@gmail.com", "Graphics", "Test Body");
	testUser.retriveNewEmail(testEmail3);

	Email testEmail4("niall@gmail.com", "Code", "Test Body");
	testUser.retriveNewEmail(testEmail4);


	testUser.searchEmailUsingSubject("Code").print();
	system("pause");
	return 0;
}

