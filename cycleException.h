#ifndef JNP1_6_CYCLEEXCEPTION_H
#define JNP1_6_CYCLEEXCEPTION_H


#include "playerException.h"

class CycleException : public PlayerException {

public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Cannot add to playlist because this would result in a cycle.";
    }
};


#endif //JNP1_6_CYCLEEXCEPTION_H