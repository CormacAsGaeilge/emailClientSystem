#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include "Attachment.h"
class Email
{
	/*******************************Stream Operators*********************************/
	friend std::ostream& operator<<(std::ostream& outStream, const Email& user);
	friend std::istream& operator >> (std::istream& inStream, Email& user);
public:
	static int count;
	/*******************************Constructor*********************************/
	Email();
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body); //multi recipient 0 attachment
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachments); //multi recipient multi attachment
	Email(std::string sender, std::string subject, std::string body);
	Email(std::string sender, std::string subject, std::string body, std::vector<Attachment> attachments);
	~Email();

	/*******************************Setters*********************************/
	void setId(unsigned int id) { Email::id = id; } 
	void setSender(std::string sender);	
	void setRecipient(std::vector<std::string> recipients); 
	void setSubject(std::string subject) { Email::subject = subject; }
	void setBody(std::string body); //Lenght >=1
	void setAttachment(std::vector<Attachment> attachments) { Email::attachments = attachments; }
	bool regexValidateTwo(std::string expression, std::string email);

	void print();

	/*******************************Getters*********************************/
	unsigned int getId() { return Email::id; }
	std::string getSender() { return Email::sender; }
	std::vector<std::string> getRecipients();
	std::string getSubject() { return Email::subject; }
	std::string getBody() { return Email::body; }
	std::time_t getDate();
	std::vector<Attachment> getAttachments() { return Email::attachments; }

	/*******************************Operator Overloading*********************************/
	bool operator>(const Email& other);
	bool operator==(const Email& other);
	bool operator!=(const Email& other);
	void operator=(const Email& other)
	{
		Email::id = other.id;
		Email::sender = other.sender;
		Email::subject = other.subject;
		Email::body = other.body;
		Email::recipients = other.recipients;
		Email::date = other.date;
		Email::attachments = other.attachments;
	}
private:
	/*******************************Variables*********************************/
	unsigned int id;
	std::string sender, subject, body;
	std::vector<std::string> recipients;
	std::time_t date; //Valid time object
	std::vector<Attachment> attachments;
};

