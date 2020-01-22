#include <sstream>
#include "file.h"


std::string* File::getDataField(const std::string& dataFieldName) {
	auto it = metadata.find(dataFieldName);
	if (it != metadata.end())
		return &(it->second);
	else return nullptr;
}

// TODO: czy tutaj w argumencie na pewno powinno byc const
File::File(const std::string& data) {
	if (data.empty())
		return;

	std::string fieldName, fieldValue;
	std::istringstream iss(data);

	std::getline(iss, fieldName, '|');
	metadata[TYPE_FIELD_NAME] = fieldName;

	while (getline(iss, fieldName, ':')) {
		// TODO: czy tutaj sie nie wywala przy pustej
		//  koncowce lub innych cornerach, wyifuj

		std::getline(iss, fieldValue, '|');
		metadata[fieldName] = fieldValue;
	}

	metadata[CONTENT_FIELD_NAME] = fieldName;
}

std::string File::getType() const {
	return metadata.at(TYPE_FIELD_NAME);
}
