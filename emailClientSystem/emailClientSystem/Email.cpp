#include "Email.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#pragma warning(disable : 4996)
using namespace std;

Email::Email():Email("defaultAddress", "defaultSubject", "defaultBody")
{

}

Email::Email(std::string recipient, std::string subject, std::string body)
{
	Email::setRecipient(recipient);
	Email::setSubject(subject);
	Email::setBody(body);
	Email::date = std::time(0);
}

Email::~Email()
{
}
 
std::time_t Email::getDate()
{
	return Email::date;
}

void Email::print()
{
	
	std::cout << "Date: " << put_time(localtime(&date), "%F %T") << endl;
	cout << "Recipient: " << recipient << endl;
	cout << "Subject: " << subject << endl;
	cout << "_______________________________" << endl;
	cout << "Body: " << body << endl;
	cout << "_______________________________" << endl;

}