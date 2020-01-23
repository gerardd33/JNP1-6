#ifndef JNP1_6_WRONGPOSITIONEXCEPTION_H
#define JNP1_6_WRONGPOSITIONEXCEPTION_H


#include "playerException.h"

class OutOfBoundsException : public PlayerException {

public:
    [[nodiscard]] const char* what() const noexcept override {
        return "out of bounds";
    }
};


#endif //JNP1_6_WRONGPOSITIONEXCEPTION_H
