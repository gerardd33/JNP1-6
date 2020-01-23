#include "playlist.h"
#include "outOfBoundsException.h"
#include "cycleException.h"


void Playlist::add(Playable *playable) {
    if (playable->isPlaylist()) {
        Playlist *playlist = dynamic_cast<Playlist *> (playable);
        if (playlist->containsPlaylist(this)) {
            throw CycleException();
        }
    }
    (this->list).push_back(playable);
}

void Playlist::add(Playable *playable, int position) {
    if (playable->isPlaylist()) {
        Playlist *playlist = dynamic_cast<Playlist *> (playable);
        if (playlist->containsPlaylist(this)) {
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

void Playlist::setMode(Mode *&mode) {
    delete this->mode;
    this->mode = mode->cloneDynamically();
}

void Playlist::setMode(Mode *&&mode) {
    delete this->mode;
    this->mode = mode;
}

void Playlist::play() {
    std::vector<unsigned int> order = this->mode->getOrder(this->list);
    for (unsigned int x : order)
        this->list[x]->play();
}

//Used to check for cycles
bool Playlist::containsPlaylist(Playlist *playlist) {
    bool result = false;
    this->list.begin();
    for (auto it = begin(this->list); it != end(this->list) && !result; ++it) {
        if ((*it)->isPlaylist()) {
            if (*it == playlist) {
                result = true;
            } else {
                Playlist *p = dynamic_cast<Playlist *> (*it);
                result = p->containsPlaylist(playlist);
            }
        }
    }
    return result;
}

