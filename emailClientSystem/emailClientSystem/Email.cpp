#include "Email.h"
#include "User.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <regex>
#pragma warning(disable : 4996) //time needs to be changed from localtime to s_localtime

int Email::count = 0;

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

bool Email::regexValidateTwo(std::string expression, std::string email)
{
	std::regex ex(expression);
	if (regex_match(email, ex)) {
		return true;
		std::cout << "true";
	}
	else
		return false;
}

void Email::setSender(std::string sender) 
{
	std::string regex = "[\\w]+@[\\w]+.[\\w]{2,3}";
	if (regexValidateTwo(regex, sender))
		Email::sender = sender;
	else
		Email::sender = "default_email";
} 


void Email::setRecipient(std::vector<std::string> recipients)
{
	for (int i = 0; i < recipients.size(); i++)
	{
		std::string regex = "[\\w]+@[\\w]+.[\\w]{2,3}";
		if (regexValidateTwo(regex, recipients[i]))
			Email::recipients = recipients;
		else
			Email::recipients[i] = "default_email";
	}
}


void Email::setBody(std::string body) 
{
	Email::body = (body.length() >= 1) ? body : "default_body";
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

	std::cout << "ID: " << id << std::endl;
	std::cout << "Date: " << std::put_time(std::localtime(&date), "%F %T") << std::endl;
	std::cout << "Recipient(s): ";
	for (int i = 0; i < recCount; i++)
		std::cout << recipients[i] << ";" << std::endl;

	std::cout << "Subject: " << subject << std::endl;
	std::cout << "_______________________________" << std::endl;
	std::cout << "Body: " << body << std::endl;
	std::cout << "_______________________________" << std::endl;
	if (attachCount != 0)
	{
		std::cout << "Attachments(s): ";
		for (int i = 0; i < attachCount; i++)
			std::cout << attachCount << ";" << std::endl;
		std::cout << "_______________________________" << std::endl;
	}
}


std::ostream& operator<<(std::ostream & outStream, const Email & email)
{
	outStream << "Name:\t";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, Email & email)
{
	std::string str;
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
