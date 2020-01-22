#ifndef JNP1_6_SONG_H
#define JNP1_6_SONG_H

#include "playable.h"
#include <iostream>

class Song : public Playable {
public:
	void play() override;
	Song(std::string artist, std::string title,
			 std::string content) : artist(std::move(artist)),
			 												title(std::move(title)),
			 												content(std::move(content)) {}

private:
	std::string artist;
	std::string title;
	std::string content;
};


#endif //JNP1_6_SONG_H
