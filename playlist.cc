#include "playlist.h"

void Playlist::add(std::shared_ptr<Playable> playable) {
    if (playable->containsObject(shared_from_this())) {
        throw CycleException();
    }
    songList.push_back(playable);
}

void Playlist::add(std::shared_ptr<Playable> playable, int position) {
    if (playable->containsObject(shared_from_this())) {
        throw CycleException();
    }
    if (position > songList.size())
        throw OutOfBoundsException();
    songList.insert(songList.begin() + position, playable);
}

void Playlist::remove() {
    if (songList.empty())
        throw OutOfBoundsException();
    songList.pop_back();
}

void Playlist::remove(int position) {
    if (position > songList.size())
        throw OutOfBoundsException();
    songList.erase(songList.begin() + position);
}

void Playlist::setMode(const std::shared_ptr<Mode>& newMode) {
    mode = newMode;
}

void Playlist::play() {
		std::cout << "Playlist [" << name << "]\n";
		std::vector<unsigned int> order = this->mode->getOrder(songList);
    for (unsigned int x : order)
        songList[x]->play();
}

Playlist::Playlist(const std::string& newName) {
    name = newName;
    songList = std::vector<std::shared_ptr<Playable>>();
    mode = std::make_shared<SequenceMode>();
}

bool Playlist::containsObject(std::shared_ptr<Playable> playable) {
    bool result = (playable.get() == this);
    for (auto it = songList.begin(); it != songList.end() && !result; ++it) {
        result = (*it)->containsObject(playable);
    }
    return result;
}
