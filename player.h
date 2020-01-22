#ifndef JNP1_6_PLAYER_H
#define JNP1_6_PLAYER_H

#include "playlist.h"
#include "file.h"
#include "sequenceMode.h"
#include "shuffleMode.h"
#include "oddEvenMode.h"
#include "song.h"
#include "movie.h"


class Player {
public:
	Playable *openFile(const File&);
	// TODO: czy te open powinny byc tutaj, czy w ich klasach, czy gdzie???
	Movie* openMovie(const File& file);
	Song* openSong(const File& file);

	Playlist *createPlaylist(std::string name);
};

// TODO: gdzie te funkcje???
SequenceMode *createSequenceMode();

ShuffleMode *createShuffleMode(int seed);

OddEvenMode *createOddEvenMode();


#endif //JNP1_6_PLAYER_H
