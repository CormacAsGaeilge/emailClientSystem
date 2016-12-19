#include "Attachment.h"
#include <iostream>
#include <fstream>

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
