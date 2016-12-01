#include <iostream>
#include "User.h"
#include "Email.h"
using namespace std;

int main()
{
	User testUser("Paddy", "password1", "paddy@gmail.com");
	Email testEmail("paddy@gmail.com", "Test Subject", "Test Body");

	testEmail.print();

	system("pause");
	return 0;
}