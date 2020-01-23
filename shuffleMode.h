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

    ~ShuffleMode() override = default;;

    ShuffleMode *cloneDynamically() override;

    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;
};


#endif //JNP1_6_SHUFFLEMODE_H
