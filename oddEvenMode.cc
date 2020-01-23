#include "oddEvenMode.h"

std::vector<unsigned int> OddEvenMode::getOrder(std::vector<Playable *> list) {
    std::vector<unsigned int> order;
    for (unsigned int odd = 1; odd < list.size(); odd += 2)
        order.push_back(odd);
    for (unsigned int even = 0; even < list.size(); even += 2)
        order.push_back(even);

    return order;
}

OddEvenMode *OddEvenMode::cloneDynamically() {
    return new OddEvenMode();
}
