#ifndef JNP1_6_MODE_H
#define JNP1_6_MODE_H

#include <vector>
#include "playable.h"

class Mode {
public:
    virtual std::vector<unsigned int> getOrder(std::vector<Playable *> list) = 0;
    virtual Mode *cloneDynamically() = 0;
    virtual ~Mode() = default;
};


#endif //JNP1_6_MODE_H
