#include "song.h"


void Song::play() {
	std::cout << "Song [" << artist << ", " << title << "]: " << content << "\n";
}

Song::Song(const File& file) {
	const std::string* tmp;
	tmp = file.getDataField(SONG_ARTIST_FIELD_NAME);
	if (tmp == nullptr)
		throw CorruptContentException();
	artist = *tmp;

	tmp = file.getDataField(SONG_TITLE_FIELD_NAME);
	if (tmp == nullptr)
		throw CorruptContentException();
	title = *tmp;

	tmp = file.getDataField(CONTENT_FIELD_NAME);
	if (tmp == nullptr)
		throw CorruptContentException();
	content = *tmp;

	if (!validateContent())
		throw CorruptContentException();
}

bool Song::validateContent() {
	for (int cur : content) {
			if (!isspace(cur) && !isalnum(cur) && std::find(std::begin(songAllowedSymbols),
						std::end(songAllowedSymbols),  cur) == std::end(songAllowedSymbols))
				return false;
	}

	return true;
}
