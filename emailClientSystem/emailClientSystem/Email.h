#pragma once
#include <string>

class Email
{
public:
	Email();
	Email(std::string recipient, std::string subject, std::string body);
	~Email();

	//Add Validation
	void setRecipient(std::string recipient) { Email::recipient = recipient; }
	void setSubject(std::string subject) { Email::subject = subject; }
	void setBody(std::string body) { Email::body = body; }

	std::string getRecipient() { return Email::recipient; }
	std::string getSubject() { return Email::subject; }
	std::string getBody() { return Email::body; }

	//Add other variables/setters/getters
private:
	std::string recipient, subject, body;
};

