#ifndef JNP1_6_SONG_H
#define JNP1_6_SONG_H

#include "playable.h"
#include "file.h"
#include "playerException.h"
#include <iostream>

const std::string ARTIST_FIELD_NAME = "artist";
const std::string TITLE_FIELD_NAME = "title";


class Song : public Playable {
public:
	bool isPlaylist() override { return false; };
	void play() override;
	explicit Song(const File& file);

private:
	std::string artist;
	std::string title;
	std::string content;
};


#endif //JNP1_6_SONG_H
