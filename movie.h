#ifndef JNP1_6_MOVIE_H
#define JNP1_6_MOVIE_H

#include "playable.h"
#include <iostream>


class Movie : public Playable {
	void play() override;
};


#endif //JNP1_6_MOVIE_H
