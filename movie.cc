#include "movie.h"

void Movie::play() {
	std::cout << "Movie [" << title << ", " << year << "]: " << content;
}

Movie::Movie(const File& file) {
	const std::string* tmp;
	tmp = file.getDataField(MOVIE_YEAR_FIELD_NAME);
	if (tmp == nullptr)
		throw CorruptContentException();
	year = *tmp;

	tmp = file.getDataField(MOVIE_TITLE_FIELD_NAME);
	if (tmp == nullptr)
		throw CorruptContentException();
	title = *tmp;

	tmp = file.getDataField(CONTENT_FIELD_NAME);
	if (tmp == nullptr)
		throw CorruptContentException();
	content = *tmp;
	std::transform(content.begin(), content.end(), content.begin(),
					[](char c){ return c - CODE_SHIFT; });
}