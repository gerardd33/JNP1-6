#ifndef JNP1_6_FILE_H
#define JNP1_6_FILE_H

#include <string>
#include <map>

class File {
public:
	File(const std::string data);
	std::string* getDataField(std::string dataFieldName);

private:
	std::map<std::string, std::string> metadata;
};


#endif //JNP1_6_FILE_H
