#ifndef JNP1_6_SONG_H
#define JNP1_6_SONG_H


#include "playable.h"
#include "file.h"
#include "corruptContentException.h"
#include <iostream>
#include <algorithm>

const std::string SONG_ARTIST_FIELD_NAME = "artist";
const std::string SONG_TITLE_FIELD_NAME = "title";
const char songAllowedSymbols[] = { ',', '.', '!', '?', '\'', ':', ';', '-' };

class Song : public Playable {
public:
	void play() override;
	bool containsObject(const std::shared_ptr<Playable>& playable) override { return (playable.get() == this); };
	explicit Song(const File& file);

private:
	std::string artist;
	std::string title;
	std::string content;
	bool validateContent();
};


#endif //JNP1_6_SONG_H
