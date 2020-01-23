#include "song.h"

void Song::play() {
	std::cout << "Song [" << artist << ", " << title << "]: " << content;
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
}
