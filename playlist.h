#ifndef JNP1_6_PLAYLIST_H
#define JNP1_6_PLAYLIST_H


#include "playable.h"
#include "sequenceMode.h"
#include "shuffleMode.h"
#include "oddEvenMode.h"
#include "outOfBoundsException.h"
#include "cycleException.h"
#include <iostream>
#include <vector>

class Playlist : public Playable, public std::enable_shared_from_this<Playlist> {
public:
	void add(const std::shared_ptr<Playable>& playable);
	void add(const std::shared_ptr<Playable>& playable, size_t position);
	void remove();
	void remove(size_t position);
	void setMode(const std::shared_ptr<Mode>& mode);
	void play() override;
	bool containsObject(const std::shared_ptr<Playable>& playable) override;

	explicit Playlist(const std::string& name);
	~Playlist() override {
		this->mode.reset();
	};

private:
    std::string name;
    std::vector<std::shared_ptr<Playable>> songList;
    std::shared_ptr<Mode> mode;
};


#endif //JNP1_6_PLAYLIST_H
