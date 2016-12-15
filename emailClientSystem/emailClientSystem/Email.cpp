#include "Email.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#pragma warning(disable : 4996)
using namespace std;

Email::Email():Email(1111,"defaultAddress", "defaultSubject", "defaultBody")
{

}

Email::Email(unsigned int id, std::string recipient, std::string subject, std::string body)
{
	Email::setId(id);
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
	
	cout << "ID: " << id << endl;
	cout << "Date: " << put_time(localtime(&date), "%F %T") << endl;
	cout << "Recipient: " << recipient << endl;
	cout << "Subject: " << subject << endl;
	cout << "_______________________________" << endl;
	cout << "Body: " << body << endl;
	cout << "_______________________________" << endl;

}