#include "Email.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#pragma warning(disable : 4996)
using namespace std;

Email::Email()
{

}

Email::Email(unsigned int id, std::string sender, std::vector<std::string> recipients, std::string subject, std::string body)
{
	Email::setId(id);
	Email::setSender(sender);
	Email::setRecipient(recipients);
	Email::setSubject(subject);
	Email::setBody(body);
	Email::date = std::time(0);
}

Email::Email(unsigned int id, std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachments)
{
	Email::setId(id);
	Email::setSender(sender);
	Email::setRecipient(recipients);
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