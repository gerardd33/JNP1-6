#include "movie.h"

void Movie::play() {
	std::cout << "Movie [" << title << ", " << year << "]: " << content;
}