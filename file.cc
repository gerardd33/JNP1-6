#include "file.h"


const std::string* File::getDataField(const std::string& dataFieldName) const {
	auto it = metadata.find(dataFieldName);
	if (it != metadata.end())
		return &(it->second);
	else return nullptr;
}

#include <iostream>

File::File(const std::string& data) {
	if (data.empty())
		return;

	std::string fieldName, fieldValue;
	std::istringstream iss(data);

	std::getline(iss, fieldName, '|');
	metadata[TYPE_FIELD_NAME] = fieldName;

	while (getline(iss, fieldName, ':')) {
		std::getline(iss, fieldValue, '|');
		metadata[fieldName] = fieldValue;
	}

	metadata[CONTENT_FIELD_NAME] = fieldName;
}

std::string File::getType() const {
	return metadata.at(TYPE_FIELD_NAME);
}
