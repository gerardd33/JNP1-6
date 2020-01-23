#ifndef JNP1_6_SEQUENCEMODE_H
#define JNP1_6_SEQUENCEMODE_H

#include "mode.h"

class SequenceMode : public Mode {
public:
    std::vector<unsigned int> getOrder(std::vector<Playable *> list) override;

    ~SequenceMode() override = default;

    SequenceMode() = default;

    SequenceMode *cloneDynamically() override;
};

#endif //JNP1_6_SEQUENCEMODE_H
