#include "movie.h"

void Movie::play() {
	std::cout << "Movie [" << title << ", " << year << "]: " << content << "\n";
}

int Movie::decode(int x) {
	if (!isalpha(x))
		return x;

	int base;
	if (isupper(x))
		base = 'A';
	else base = 'a';

	x -= base;
	x -= CODE_SHIFT;
	if (x < 0)
		x += ALPHABET_SIZE;
	x += base;
	return x;
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
	std::transform(content.begin(), content.end(), content.begin(), decode);
}