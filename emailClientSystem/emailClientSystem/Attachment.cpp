#include "Attachment.h"
#include <iostream>
#include <fstream>
#include <string>

Attachment::Attachment()
{
}


Attachment::Attachment(std::string fileName, std::string fileSuffix)
{
	Attachment::setFileName(fileName);
	Attachment::setFileSuffix(fileSuffix);
	Attachment::setFileData();
}

Attachment::~Attachment()
{
}

void Attachment::setFileData()
{
	std::ifstream ifs(Attachment::getFileName() + "." + Attachment::getFileSuffix());
	/**************STACKOVERFLOW - http://stackoverflow.com/questions/7352099/stdstring-to-char *************/
	std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	Attachment::fileData = &str[0u];
}

std::string Attachment::getFileData()
{
	return Attachment::fileData;
}


std::ostream& operator<<(std::ostream & outStream, const Attachment & email)
{
	outStream << "Name:\t";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, Attachment & email)
{
	std::string str;
	inStream >> str;
	return inStream;
}

bool Attachment::operator>(const Attachment &other)
{
	if (Attachment::getFileName() > other.fileName)
		return true;
	else
		return false;
}

bool Attachment::operator==(const Attachment & other)
{
	if (Attachment::getFileName() == other.fileName)
		return true;
	else
		return false;
}

bool Attachment::operator!=(const Attachment & other)
{
	if (Attachment::getFileName() != other.fileName)
		return true;
	else
		return false;
}
