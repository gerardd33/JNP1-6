#ifndef SHUFFLEMODE_H
#define SHUFFLEMODE_H

#include "mode.h"

class ShuffleMode : public Mode {
private:
    int seed;
public:
    ShuffleMode(int seed) : seed(seed) {}

    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;
};


#endif //SHUFFLEMODE_H
