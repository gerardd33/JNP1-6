#ifndef JNP1_6_PLAYER_H
#define JNP1_6_PLAYER_H


#include "file.h"
#include "song.h"
#include "movie.h"
#include "playlist.h"
#include "sequenceMode.h"
#include "shuffleMode.h"
#include "oddEvenMode.h"
#include "unsupportedTypeException.h"

class Player {
public:
    static std::shared_ptr<Playable> openFile(const File&);
    static std::shared_ptr<Playlist> createPlaylist(const std::string& name);
};

std::shared_ptr<SequenceMode> createSequenceMode();
std::shared_ptr<ShuffleMode> createShuffleMode(int seed);
std::shared_ptr<OddEvenMode> createOddEvenMode();


#endif //JNP1_6_PLAYER_H
