#ifndef JNP1_6_CORRUPTFILEEXCEPTION_H
#define JNP1_6_CORRUPTFILEEXCEPTION_H


#include "playerException.h"

class CorruptFileException : public PlayerException {
public:
	[[nodiscard]] const char* what() const noexcept override {
		return "corrupt file";
	}
};


#endif //JNP1_6_CORRUPTFILEEXCEPTION_H
