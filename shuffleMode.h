#ifndef SHUFFLEMODE_H
#define SHUFFLEMODE_H

#include "mode.h"
#include <random>

class ShuffleMode : public Mode {
private:
    std::default_random_engine engine;
public:
    ShuffleMode(int seed) : engine(std::default_random_engine(seed)) {}

    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;
};


#endif //SHUFFLEMODE_H
