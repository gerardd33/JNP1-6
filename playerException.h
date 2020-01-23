#ifndef JNP1_6_PLAYEREXCEPTION_H
#define JNP1_6_PLAYEREXCEPTION_H

#include <string>

class PlayerException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Player error.";
    }
};

#endif //JNP1_6_PLAYEREXCEPTION_H
