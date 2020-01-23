#ifndef JNP1_6_SONG_H
#define JNP1_6_SONG_H

#include "playable.h"
#include "file.h"
#include "corruptContentException.h"
#include <iostream>
#include <memory>

const std::string SONG_ARTIST_FIELD_NAME = "artist";
const std::string SONG_TITLE_FIELD_NAME = "title";

class Song : public Playable {
public:
	bool containsObject(std::shared_ptr<Playable> playable) override { return (playable.get() == this); };
	void play() override;
	explicit Song(const File& file);

private:
	std::string artist;
	std::string title;
	std::string content;
};


#endif //JNP1_6_SONG_H
