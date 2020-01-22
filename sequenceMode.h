#ifndef SEQUENCEMODE_H
#define SEQUENCEMODE_H


#include "mode.h"

class SequenceMode : public Mode {
public:
    std::vector<unsigned int> getOrder() override;
};


#endif //SEQUENCEMODE_H
