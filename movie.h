#ifndef JNP1_6_MOVIE_H
#define JNP1_6_MOVIE_H


#include "playable.h"
#include "file.h"
#include "corruptContentException.h"
#include <iostream>
#include <algorithm>
#include <memory>

const std::string MOVIE_YEAR_FIELD_NAME = "year";
const std::string MOVIE_TITLE_FIELD_NAME = "title";
const int CODE_SHIFT = 13;
const int ALPHABET_SIZE = 26;
const char movieAllowedSymbols[] = { ',', '.', '!', '?', '\'', ':', ';', '-' };

class Movie : public Playable {
public:
	bool containsObject(std::shared_ptr<Playable> playable) override { return (playable.get() == this); };
	void play() override;
	explicit Movie(const File& file);

private:
	std::string year;
	std::string title;
	std::string content;
	static int decode(int x);
	bool validateData();
};


#endif //JNP1_6_MOVIE_H
