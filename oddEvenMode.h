#ifndef JNP1_6_ODDEVENMODE_H
#define JNP1_6_ODDEVENMODE_H


#include "mode.h"

class OddEvenMode : public Mode {
public:
    std::vector<size_t> getOrder(std::vector<std::shared_ptr<Playable>> list) override;
    OddEvenMode() = default;
};


#endif //JNP1_6_ODDEVENMODE_H
