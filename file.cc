#include "file.h"

std::string* File::getDataField(std::string dataFieldName) {
	auto it = metadata.find(dataFieldName);
	if (it != metadata.end())
		return &(it->second);
	else return nullptr;
}

// TODO: czy tutaj w argumencie powinna byc const referencja?
File::File(std::string data) {
	// TODO: parser
	//  ...
}