#include "playlist.h"
#include "outOfBoundsException.h"
#include "cycleException.h"
#include "player.h"


void Playlist::add(std::shared_ptr<Playable> playable) {
    if (playable->isPlaylist()) {
        std::shared_ptr<Playlist> playlist = std::dynamic_pointer_cast<Playlist>(playable);
        if (playlist->containsPlaylist(shared_from_this())) {
            throw CycleException();
        }
    }
    (this->list).push_back(playable);
}

void Playlist::add(std::shared_ptr<Playable> playable, int position) {
    if (playable->isPlaylist()) {
        std::shared_ptr<Playlist> playlist = std::dynamic_pointer_cast<Playlist>(playable);
        if (playlist->containsPlaylist(shared_from_this())) {
            throw CycleException();
        }
    }
    if (position > (this->list).size()) {
        throw OutOfBoundsException();
    }
    (this->list).insert((this->list).begin() + position, playable);
}

void Playlist::remove() {
    if ((this->list).empty()) {
        throw OutOfBoundsException();
    }
    (this->list).pop_back();
}

void Playlist::remove(int position) {
    if (position > (this->list).size()) {
        throw OutOfBoundsException();
    }
    (this->list).erase((this->list).begin() + position);
}

void Playlist::setMode(const std::shared_ptr<Mode> &mode) {
//    this->mode.reset();
    this->mode = mode;
}

void Playlist::play() {
    std::vector<unsigned int> order = this->mode->getOrder(this->list);
    for (unsigned int x : order)
        this->list[x]->play();
}

//Used to check for cycles
bool Playlist::containsPlaylist(std::shared_ptr<Playlist> playlist) {
    bool result = false;
    this->list.begin();
    for (auto it = begin(this->list); it != end(this->list) && !result; ++it) {
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

Playlist::Playlist(const std::string &name) {
    this->name = name;
    this->list = std::vector<std::shared_ptr<Playable>>();
    this->mode = createSequenceMode();
}

