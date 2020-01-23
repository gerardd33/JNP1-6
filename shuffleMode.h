#ifndef JNP1_6_SHUFFLEMODE_H
#define JNP1_6_SHUFFLEMODE_H

#include "mode.h"
#include <random>

class ShuffleMode : public Mode {
private:
    std::default_random_engine engine;
    int seed;
public:
    explicit ShuffleMode(int seed) : engine(std::default_random_engine(seed)), seed(seed) {};

    std::vector<unsigned int> getOrder(std::vector<std::shared_ptr<Playable>> list) override;
};


#endif //JNP1_6_SHUFFLEMODE_H
