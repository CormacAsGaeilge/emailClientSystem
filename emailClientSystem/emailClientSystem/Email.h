#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include "Attachment.h"
class Email
{

	friend std::ostream& operator<<(std::ostream& outStream, const Email& user);
	friend std::istream& operator >> (std::istream& inStream, Email& user);
public:
	static int count;
	Email();
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body); //multi recipient 0 attachment
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachments); //multi recipient multi attachment
	Email(std::string sender, std::string subject, std::string body);
	Email(std::string sender, std::string subject, std::string body, std::vector<Attachment> attachments);
	~Email();

	//Add Validation
	void setId(unsigned int id) { Email::id = id; } 
	void setSender(std::string sender);	//Valid email (regex) 
	void setRecipient(std::vector<std::string> recipients); //Valid email(s) (regex) 
	void setSubject(std::string subject) { Email::subject = subject; }
	void setBody(std::string body); //Lenght >=1
	void setAttachment(std::vector<Attachment> attachments) { Email::attachments = attachments; }
	bool regexValidateTwo(std::string expression, std::string email);

	void print();

	unsigned int getId() { return Email::id; }
	std::string getSender() { return Email::sender; }
	std::vector<std::string> getRecipients();
	std::string getSubject() { return Email::subject; }
	std::string getBody() { return Email::body; }
	std::time_t getDate();
	std::vector<Attachment> getAttachments() { return Email::attachments; }

	//(==, !=, =, <<, and >>)
	bool operator>(const Email& other);
	bool operator==(const Email& other);
	bool operator!=(const Email& other);
private:
	unsigned int id;
	std::string sender, subject, body;
	std::vector<std::string> recipients;
	std::time_t date; //Valid time object
	std::vector<Attachment> attachments;
};

