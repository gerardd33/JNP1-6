#ifndef JNP1_6_PLAYLIST_H
#define JNP1_6_PLAYLIST_H


#include "playable.h"
#include "mode.h"
#include "outOfBoundsException.h"
#include "cycleException.h"
#include <vector>
#include <memory>

class Playlist : public Playable, public std::enable_shared_from_this<Playlist> {
public:
	void add(std::shared_ptr<Playable> playable);
	void add(std::shared_ptr<Playable> playable, int position);
	void remove();
	void remove(int position);
	void setMode(const std::shared_ptr<Mode>& mode);
	bool containsObject(std::shared_ptr<Playable> playable) override;
	void play() override;

	explicit Playlist(const std::string& name);

	~Playlist() {
		this->mode.reset();
	};

private:
    std::string name;
    std::vector<std::shared_ptr<Playable>> songList;
    std::shared_ptr<Mode> mode;
};


#endif //JNP1_6_PLAYLIST_H
