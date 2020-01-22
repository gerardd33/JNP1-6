#ifndef JNP1_6_LIB_PLAYLIST_H
#define JNP1_6_LIB_PLAYLIST_H

#include "file.h"
#include "playable.h"
#include "playerException.h"
#include <string>
#include <vector>
#include "mode.h"
#include "sequenceMode.h"
#include "shuffleMode.h"
#include "oddEvenMode.h"


class Playlist : public Playable {
private:
    std::vector<Playable *> list;
    Mode *mode;
public:
    void add(Playable *playable);

    void add(Playable *playable, int position);

    void remove();

    void remove(int position);

    void setMode(Mode *mode);
};

class Player {
public:
    Playable *openFile(const File &);

    Playlist *createPlaylist(std::string name);
};

SequenceMode *createSequenceMode();

ShuffleMode *createShuffleMode(int seed);

OddEvenMode *createOddEvenMode();

#endif //JNP1_6_LIB_PLAYLIST_H
