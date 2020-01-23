#ifndef JNP1_6_PLAYABLE_H
#define JNP1_6_PLAYABLE_H


#include <memory>

class Playable {
public:
	virtual void play() = 0;
	virtual bool containsObject(const std::shared_ptr<Playable>& playable) = 0;
	virtual ~Playable() = default;
};


#endif //JNP1_6_PLAYABLE_H
