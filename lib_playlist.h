#ifndef JNP1_6_LIB_PLAYLIST_H
#define JNP1_6_LIB_PLAYLIST_H

#include <string>
#include "file.h"
#include "playable.h"
#include "playerException.h"


class Player {
public:
	Playable* openFile(const File&);
	Playlist* createPlaylist(std::string name);
};

SequenceMode* createSequenceMode();
ShuffleMode* createShuffleMode(int seed);
OddEvenMode* createOddEvenMode();

#endif //JNP1_6_LIB_PLAYLIST_H
