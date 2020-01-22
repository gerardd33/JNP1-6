#ifndef JNP1_6_MOVIE_H
#define JNP1_6_MOVIE_H

#include "playable.h"
#include <iostream>


class Movie : public Playable {
public:
	void play() override;
	Movie(std::string year, std::string title,
				std::string content) : year(std::move(year)),
															 title(std::move(title)),
															 content(std::move(content)) {}

private:
	std::string year;
	std::string title;
	std::string content;
};


#endif //JNP1_6_MOVIE_H
