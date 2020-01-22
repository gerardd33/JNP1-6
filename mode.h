#ifndef MODE_H
#define MODE_H

#include <vector>
#include "playable.h"

class Mode {
public:
    virtual std::vector<unsigned int> getOrder(std::vector<Playable *> list) = 0;
};


#endif //MODE_H
