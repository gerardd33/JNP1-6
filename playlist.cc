#include "playlist.h"


void Playlist::add(Playable *playable) {
    if (playable->isPlaylist()) {
        Playlist *playlist = (Playlist *) playable;
        if (playlist->containsPlaylist(this)) {
            throw PlayerException();
        }
    }
    (this->list).push_back(playable);
}

void Playlist::add(Playable *playable, int position) {
    if (position > (this->list).size()) {
        throw PlayerException();
    }
    (this->list).insert((this->list).begin() + position, playable);
}

void Playlist::remove() {
    if ((this->list).empty()) {
        throw PlayerException();
    }
    (this->list).pop_back();
}

void Playlist::remove(int position) {
    if (position > (this->list).size()) {
        throw PlayerException();
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
                Playlist *p = (Playlist *) (*it);
                result = p->containsPlaylist(playlist);
            }
        }
    }
    return result;
}

