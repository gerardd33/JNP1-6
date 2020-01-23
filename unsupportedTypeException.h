#ifndef JNP1_6_UNSUPPORTEDTYPEEXCEPTION_H
#define JNP1_6_UNSUPPORTEDTYPEEXCEPTION_H


#include "playerException.h"

class UnsupportedTypeException : public PlayerException {
public:
	[[nodiscard]] const char* what() const noexcept override {
		return "unsupported type";
	}
};


#endif //JNP1_6_UNSUPPORTEDTYPEEXCEPTION_H
