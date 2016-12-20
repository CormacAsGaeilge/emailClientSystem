#pragma once
#include <string>
class Attachment
{
	/*******************************Stream Operators*********************************/
	friend std::ostream& operator<<(std::ostream& outStream, const Attachment& user);
	friend std::istream& operator >> (std::istream& inStream, Attachment& user);

public:
	/*******************************Constructor*********************************/
	Attachment();
	Attachment(std::string fileName, std::string fileSuffix);
	~Attachment();

	/*******************************Setters*********************************/
	void setFileName(std::string fileName) { Attachment::fileName = fileName; }
	void setFileSuffix(std::string fileSuffix) { Attachment::fileSuffix = fileSuffix; }
	void setFileData();

	/*******************************Getters*********************************/
	std::string getFileName() { return Attachment::fileName; }
	std::string getFileSuffix() { return Attachment::fileSuffix; }
	std::string Attachment::getFileData();

	/*******************************Operator Overloading*********************************/
	//(==, !=, =, <<, and >>)
	bool operator>(const Attachment& other);
	bool operator==(const Attachment& other);
	bool operator!=(const Attachment& other);
private:
	std::string fileName, fileSuffix;
	const char* fileData;
};

