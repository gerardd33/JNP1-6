#ifndef JNP1_6_MODE_H
#define JNP1_6_MODE_H

#include <vector>
#include <memory>
#include "playable.h"

class Mode {
public:
    virtual std::vector<unsigned int> getOrder(std::vector<std::shared_ptr<Playable>> list) = 0;
};


#endif //JNP1_6_MODE_H
