#include "movie.h"

void Movie::play() {
	std::cout << "Movie [" << title << ", " << year << "]: " << content;
}

Movie::Movie(const File &file) {
	const std::string* tmp;
	tmp = file.getDataField(MOVIE_YEAR_FIELD_NAME);
	if (tmp == nullptr)
		throw PlayerException(); // TODO: corrupt content exception
	year = *tmp;
	// TODO: czy tu na pewno sie kopiuje ??? powinno

	tmp = file.getDataField(MOVIE_TITLE_FIELD_NAME);
	if (tmp == nullptr)
		throw PlayerException(); // TODO: corrupt content exception
	title = *tmp;

	tmp = file.getDataField(CONTENT_FIELD_NAME);
	if (tmp == nullptr)
		throw PlayerException(); // TODO: corrupt content exception
	content = *tmp;
	std::transform(content.begin(), content.end(), content.begin(), [](char c){ return c - CODE_SHIFT; });
}