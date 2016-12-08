#include <iostream>
#include "User.h"
#include "Email.h"


int main()
{
	User testUser("Paddy", "password1", "paddy@gmail.com");
	Email testEmail("paddy@gmail.com", "Test Subject", "Test Body");

	testEmail.print();

	testUser.searchEmailUsingSubject("Paddy");

	system("pause");
	return 0;
}

