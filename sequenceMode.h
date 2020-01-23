#ifndef JNP1_6_SEQUENCEMODE_H
#define JNP1_6_SEQUENCEMODE_H


#include "mode.h"
#include <numeric>


class SequenceMode : public Mode {
public:
    std::vector<size_t> getOrder(std::vector<std::shared_ptr<Playable>> list) override;
    SequenceMode() = default;
};


#endif //JNP1_6_SEQUENCEMODE_H
