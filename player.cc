#include "player.h"


Playlist* Player::createPlaylist(std::string name) {
	return nullptr; //TODO cykle
}

Playable* Player::openFile(const File& file) {
	// TODO: jak z tymi pointerami tu, jakis smart, dynamic_cast?
	Playable* result;
	std::string type = file.getType();

	if (type == "audio")
		result = new Song(file);
	else if (type == "video")
		result = new Movie(file);
	else throw PlayerException();
	// TODO: zmien na unsupported type exception

	return result;
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