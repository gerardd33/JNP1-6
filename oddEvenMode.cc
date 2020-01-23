#include "oddEvenMode.h"

std::vector<size_t> OddEvenMode::getOrder(std::vector<std::shared_ptr<Playable>> list) {
    std::vector<size_t> order;
    for (size_t odd = 1; odd < list.size(); odd += 2) {
			order.push_back(odd);
    }
    for (size_t even = 0; even < list.size(); even += 2) {
			order.push_back(even);
    }

    return order;
}
