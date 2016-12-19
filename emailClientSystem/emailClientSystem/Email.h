#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include "Attachment.h"
class Email
{


	int count = 0;


public:
	Email();
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body); //multi recipient 0 attachment
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachments); //multi recipient multi attachment
	Email(std::string sender, std::string subject, std::string body); //multi recipient 0 attachment
	Email(std::string sender, std::string subject, std::string body, std::vector<Attachment> attachments); //multi recipient multi attachment

	~Email();

	//Add Validation
	void setId(unsigned int id) { Email::id = id; } 
	void setSender(std::string sender) { Email::sender = sender; } //Valid email (regex) 
	void setRecipient(std::vector<std::string> recipients); //Valid email(s) (regex) 
	void setSubject(std::string subject) { Email::subject = subject; }
	void setBody(std::string body) { Email::body = body; } //Length >= 1 character
	void setAttachment(std::vector<Attachment> attachments) { Email::attachments = attachments; }


	//Attachment(s) Properly instanciate Attachment object(s) Text file, Logo.png
	void print();

	unsigned int getId() { return Email::id; }
	std::string getSender() { return Email::sender; }
	std::vector<std::string> getRecipients();
	std::string getSubject() { return Email::subject; }
	std::string getBody() { return Email::body; }
	std::time_t getDate();
	std::vector<Attachment> getAttachments() { return Email::attachments; }

	//print - char* dt = ctime(&now); cout << "The local date and time is: " << dt << endl;

	//Add other variables/setters/getters
private:
	unsigned int id;
	std::string sender, subject, body;
	std::vector<std::string> recipients;
	std::time_t date; //Valid time object
	std::vector<Attachment> attachments;
	
};

