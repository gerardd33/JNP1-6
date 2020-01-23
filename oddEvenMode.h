#ifndef JNP1_6_ODDEVENMODE_H
#define JNP1_6_ODDEVENMODE_H


#include "mode.h"

class OddEvenMode : public Mode {
public:
    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;

    ~OddEvenMode() override = default;

    OddEvenMode() = default;

    OddEvenMode* cloneDynamically() override;
};

#endif //JNP1_6_ODDEVENMODE_H
