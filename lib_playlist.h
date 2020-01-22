#ifndef JNP1_6_LIB_PLAYLIST_H
#define JNP1_6_LIB_PLAYLIST_H

#include "player.h"
#include "playlist.h"
#include "sequenceMode.h"
#include "shuffleMode.h"
#include "oddEvenMode.h"


// TODO: gdzie te funkcje???
SequenceMode *createSequenceMode();

ShuffleMode *createShuffleMode(int seed);

OddEvenMode *createOddEvenMode();

#endif //JNP1_6_LIB_PLAYLIST_H
