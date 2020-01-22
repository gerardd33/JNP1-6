#ifndef ODDEVENMODE_H
#define ODDEVENMODE_H


#include "mode.h"

class OddEvenMode : public Mode {
public:
    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;
};

#endif //ODDEVENMODE_H
