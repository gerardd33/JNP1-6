#ifndef JNP1_6_MOVIE_H
#define JNP1_6_MOVIE_H

#include "playable.h"
#include "file.h"
#include "playerException.h"
#include <iostream>
#include <algorithm>

const std::string YEAR_FIELD_NAME = "year";
const std::string TITLE_FIELD_NAME = "title";
const int CODE_SHIFT = 13;


class Movie : public Playable {
public:
	bool isPlaylist() override { return false; };
	void play() override;
	explicit Movie(const File& file);

private:
	std::string year;
	std::string title;
	std::string content;
};


#endif //JNP1_6_MOVIE_H
