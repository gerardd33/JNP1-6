#include "movie.h"

void Movie::play() {
	std::cout << "Movie [" << title << ", " << year << "]: " << content << "\n";
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

	if (!validateData())
		throw CorruptContentException();
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

bool Movie::validateData() {
	for (int cur : content) {
		if (!isspace(cur) && !isalnum(cur) && std::find(std::begin(movieAllowedSymbols),
																										std::end(movieAllowedSymbols),  cur) == std::end(movieAllowedSymbols))
			return false;
	}

	return true;
}

