#ifndef JNP1_6_SEQUENCEMODE_H
#define JNP1_6_SEQUENCEMODE_H

#include "mode.h"

class SequenceMode : public Mode {
public:
    std::vector<unsigned int> getOrder(std::vector<std::shared_ptr<Playable>> list) override;

    SequenceMode() = default;

};

#endif //JNP1_6_SEQUENCEMODE_H
