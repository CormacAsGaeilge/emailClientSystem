#pragma once
#include <string>
#include <ctime>
#include <chrono>

class Email
{
public:
	Email();
	Email(unsigned int id, std::string recipient, std::string subject, std::string body);
	~Email();

	//Add Validation
	void setId(unsigned int id) { Email::id = id; }
	void setRecipient(std::string recipient) { Email::recipient = recipient; }
	void setSubject(std::string subject) { Email::subject = subject; }
	void setBody(std::string body) { Email::body = body; }
	void print();

	unsigned int getId() { return Email::id; }
	std::string getRecipient() { return Email::recipient; }
	std::string getSubject() { return Email::subject; }
	std::string getBody() { return Email::body; }
	std::time_t getDate();

	//print - char* dt = ctime(&now); cout << "The local date and time is: " << dt << endl;

	//Add other variables/setters/getters
private:
	unsigned int id;
	std::string recipient, subject, body;
	std::time_t date;
};

