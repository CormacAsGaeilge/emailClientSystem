#include "Email.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#pragma warning(disable : 4996) //time needs to be changed from localtime to s_localtime
using namespace std;

Email::Email()
{

}

Email::Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body)
{
	Email::setId(count++);
	Email::setSender(sender);
	Email::setRecipient(recipients);
	Email::setSubject(subject);
	Email::setBody(body);
	Email::date = std::time(0);
}

Email::Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachments)
{
	Email::setId(count++);
	Email::setSender(sender);
	Email::setRecipient(recipients);
	Email::setSubject(subject);
	Email::setBody(body);
	Email::date = std::time(0);
	Email::setAttachment(attachments);
}

Email::Email(std::string sender, std::string subject, std::string body)
{
	Email::setId(count++);
	Email::setSender(sender);
	Email::setSubject(subject);
	Email::setBody(body);
	Email::date = std::time(0);
}

Email::Email(std::string sender, std::string subject, std::string body, std::vector<Attachment> attachments)
{
	Email::setId(count++);
	Email::setSender(sender);
	Email::setSubject(subject);
	Email::setBody(body);
	Email::date = std::time(0);
	Email::setAttachment(attachments);
}

Email::~Email()
{
}

void Email::setRecipient(std::vector<std::string> recipients)
{
	Email::recipients = recipients;
}
 
std::vector<std::string> Email::getRecipients()
{
	return recipients;
}

std::time_t Email::getDate()
{
	return Email::date;
}

void Email::print()
{
	int recCount = Email::recipients.size(), attachCount = Email::attachments.size();

	cout << "ID: " << id << endl;
	cout << "Date: " << put_time(localtime(&date), "%F %T") << endl;
	cout << "Recipient(s): ";
	for(int i = 0; i < recCount; i++)
		cout << recipients[i] << ";" << endl;

	cout << "Subject: " << subject << endl;
	cout << "_______________________________" << endl;
	cout << "Body: " << body << endl;
	cout << "_______________________________" << endl;
	if (attachCount != 0)
	{
		cout << "Attachments(s): ";
		for (int i = 0; i < attachCount; i++)
			cout << attachCount << ";" << endl;
		cout << "_______________________________" << endl;
	}
}


std::ostream& operator<<(ostream & outStream, const Email & email)
{
	outStream << "Name:\t";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, Email & email)
{
	string str;
	inStream >> str;
	return inStream;
}

bool Email::operator>(const Email &other)
{
	if (Email::getBody() > other.body)
		return true;
	else
		return false;
}

bool Email::operator==(const Email & other)
{
	if (Email::getBody() == other.body)
		return true;
	else
		return false;
}

bool Email::operator!=(const Email & other)
{
	if (Email::getBody() != other.body)
		return true;
	else
		return false;
}
