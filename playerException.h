#ifndef JNP1_6_PLAYEREXCEPTION_H
#define JNP1_6_PLAYEREXCEPTION_H

#include <string>

class PlayerException : public std::exception {
public:
    [[nodiscard]] virtual const char* what() const noexcept {
        return "player error";
    }
};

#endif //JNP1_6_PLAYEREXCEPTION_H
