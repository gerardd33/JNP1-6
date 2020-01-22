#include <sstream>
#include "file.h"


std::string* File::getDataField(std::string dataFieldName) {
	auto it = metadata.find(dataFieldName);
	if (it != metadata.end())
		return &(it->second);
	else return nullptr;
}

// TODO: czy tutaj w argumencie powinno byc const
File::File(std::string& data) {
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