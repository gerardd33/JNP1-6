#include <random>
#include <algorithm>
#include "shuffleMode.h"

std::vector<unsigned int> ShuffleMode::getOrder(std::vector<Playable *> list) {
    std::vector<unsigned int> order(list.size());
    std::iota(std::begin(order), std::end(order), 0); // order is {0, 1, 2, ... list.size() - 1}
    std::shuffle(order.begin(), order.end(), std::default_random_engine(this->seed));
    return order;
}

