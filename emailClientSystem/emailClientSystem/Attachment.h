#pragma once
#include <string>
class Attachment
{
public:
	Attachment();
	Attachment(std::string fileName, std::string fileSuffix, char fileData[]);
	~Attachment();

	void setFileName(std::string fileName) { Attachment::fileName = fileName; }
	void setFileSuffix(std::string fileSuffix) { Attachment::fileSuffix = fileSuffix; }
	void fileData();

	std::string getFileName() { return Attachment::fileName; }
	std::string getFileSuffix() { return Attachment::fileSuffix; }
	void getFileData();
private:
	std::string fileName, fileSuffix;
	//char fileData[];
};

