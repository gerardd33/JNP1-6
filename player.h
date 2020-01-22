#ifndef JNP1_6_PLAYER_H
#define JNP1_6_PLAYER_H

#include "playlist.h"
#include "file.h"


class Player {
public:
	Playable *openFile(const File&);

	Playlist *createPlaylist(std::string name);
};


#endif //JNP1_6_PLAYER_H
