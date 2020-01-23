#ifndef JNP1_6_MODE_H
#define JNP1_6_MODE_H


#include "playable.h"
#include <vector>
#include <memory>

class Mode {
public:
    virtual std::vector<unsigned int> getOrder(std::vector<std::shared_ptr<Playable>> list) = 0;
    virtual ~Mode() = default;
};


#endif //JNP1_6_MODE_H
