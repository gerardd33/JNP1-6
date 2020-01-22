#include "playlist.h"


void Playlist::add(Playable *playable) {
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

void Playlist::setMode(Mode *newMode) {
    this->mode = newMode;
}

void Playlist::play() {
    std::vector<unsigned int> order = this->mode->getOrder(this->list);
    for (unsigned int x : order)
        this->list[x]->play();
}

