#include "song.h"

void Song::play() {
	std::cout << "Song [" << artist << ", " << title << "]: " << content;
}

Song::Song(const File &file) {
	const std::string* tmp;
	tmp = file.getDataField(SONG_ARTIST_FIELD_NAME);
	if (tmp == nullptr)
		throw PlayerException(); // TODO: corrupt content exception
	artist = *tmp;
	// TODO: czy tu na pewno sie kopiuje ??? powinno

	tmp = file.getDataField(SONG_TITLE_FIELD_NAME);
	if (tmp == nullptr)
		throw PlayerException(); // TODO: corrupt content exception
	title = *tmp;

	tmp = file.getDataField(CONTENT_FIELD_NAME);
	if (tmp == nullptr)
		throw PlayerException(); // TODO: corrupt content exception
	content = *tmp;
}
