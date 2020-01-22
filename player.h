#ifndef JNP1_6_PLAYER_H
#define JNP1_6_PLAYER_H

#include "playlist.h"
#include "file.h"
#include "sequenceMode.h"
#include "shuffleMode.h"
#include "oddEvenMode.h"


class Player {
public:
	Playable *openFile(const File&);

	Playlist *createPlaylist(std::string name);
};

// TODO: gdzie te funkcje???
SequenceMode *createSequenceMode();

ShuffleMode *createShuffleMode(int seed);

OddEvenMode *createOddEvenMode();


#endif //JNP1_6_PLAYER_H
