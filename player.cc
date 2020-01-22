#include "player.h"


Playable* Player::openFile(const File& file) {
	// TODO: jak z tymi pointerami tu, jakis smart, dynamic_cast?
	Playable* result;
	std::string type = file.getType();

	if (type == "audio")
		result = openSong(file);
	else if (type == "video")
		result = openMovie(file);
	else throw PlayerException();
	// TODO: zmien na unsupported type exception

	return result;
}

Playlist* Player::createPlaylist(std::string name) {
	return nullptr; //TODO cykle
}

SequenceMode* createSequenceMode() {
	// ...
}

ShuffleMode* createShuffleMode(int seed) {
	// ...
}

OddEvenMode* createOddEvenMode() {
	// ...
}