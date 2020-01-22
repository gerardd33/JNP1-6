#ifndef JNP1_6_PLAYLIST_H
#define JNP1_6_PLAYLIST_H

#include "playable.h"
#include "mode.h"
#include "playerException.h"
#include <vector>


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


#endif //JNP1_6_PLAYLIST_H
