#ifndef JNP1_6_CORRUPTCONTENTEXCEPTION_H
#define JNP1_6_CORRUPTCONTENTEXCEPTION_H


#include "playerException.h"

class CorruptContentException : public PlayerException {
public:
	[[nodiscard]] const char* what() const noexcept override {
		return "corrupt content";
	}
};


#endif //JNP1_6_CORRUPTCONTENTEXCEPTION_H
