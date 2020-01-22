#ifndef SEQUENCEMODE_H
#define SEQUENCEMODE_H

#include "mode.h"

class SequenceMode : public Mode {
public:
    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;
};

#endif //SEQUENCEMODE_H
