#include "playlist.h"

void Playlist::add(std::shared_ptr<Playable> playable) {
    if (playable->isPlaylist()) {
        std::shared_ptr<Playlist> playlist = std::dynamic_pointer_cast<Playlist>(playable);
        if (playlist->containsPlaylist(shared_from_this()))
            throw CycleException();
    }
    songList.push_back(playable);
}

void Playlist::add(std::shared_ptr<Playable> playable, int position) {
    if (playable->isPlaylist()) {
        std::shared_ptr<Playlist> playlist = std::dynamic_pointer_cast<Playlist>(playable);
        if (playlist->containsPlaylist(shared_from_this()))
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
    std::vector<unsigned int> order = this->mode->getOrder(songList);
    for (unsigned int x : order)
        songList[x]->play();
}

// Used to check for cycles
bool Playlist::containsPlaylist(std::shared_ptr<Playlist> playlist) {
    bool result = false;
    songList.begin();
    for (auto it = songList.begin(); it != songList.end() && !result; ++it) {
        if ((*it)->isPlaylist()) {
            if (*it == playlist) {
                result = true;
            } else {
                std::shared_ptr<Playlist> p = std::dynamic_pointer_cast<Playlist>(*it);
                result = p->containsPlaylist(playlist);
            }
        }
    }
    return result;
}

Playlist::Playlist(const std::string& newName) {
    name = newName;
    songList = std::vector<std::shared_ptr<Playable>>();
    mode = createSequenceMode();
}
