#ifndef SHUFFLEMODE_H
#define SHUFFLEMODE_H


#include "mode.h"

class ShuffleMode : public Mode {
public:
    std::vector<unsigned int> getOrder() override;
};


#endif //SHUFFLEMODE_H
