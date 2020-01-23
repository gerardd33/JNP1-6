#ifndef JNP1_6_FILE_H
#define JNP1_6_FILE_H

#include <string>
#include <map>

const std::string TYPE_FIELD_NAME = "|type";
const std::string CONTENT_FIELD_NAME = "|content";


class File {
public:
	explicit File(const std::string& data);
	[[nodiscard]] const std::string* getDataField(const std::string& dataFieldName) const;
	[[nodiscard]] std::string getType() const;

private:
	std::map<std::string, std::string> metadata;
};


#endif //JNP1_6_FILE_H
