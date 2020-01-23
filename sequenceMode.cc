#include "sequenceMode.h"


std::vector<size_t> SequenceMode::getOrder(std::vector<std::shared_ptr<Playable>> list) {
    std::vector<size_t> order(list.size());
    std::iota(std::begin(order), std::end(order), 0); // order is {0, 1, 2, ... list.size() - 1}
    return order;
}

