#include "Email.h"



Email::Email():Email("defaultAddress", "defaultSubject", "defaultBody")
{

}

Email::Email(std::string recipient, std::string subject, std::string body)
{
	Email::setRecipient(recipient);
	Email::setSubject(subject);
	Email::setBody(body);
}

Email::~Email()
{
}
