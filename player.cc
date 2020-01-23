#include "player.h"

Playlist *Player::createPlaylist(const std::string &name) {
    Playlist *playlist = new Playlist(name);
    auto mode = createSequenceMode();
    playlist->setMode(mode);
    playlists.push_back(playlist);
    return playlist;
}

Playable *Player::openFile(const File &file) {
    // TODO: jak z tymi pointerami tu, jakis smart, dynamic_cast?
    Playable *result;
    std::string type = file.getType();

    if (type == "audio")
        result = new Song(file);
    else if (type == "video")
        result = new Movie(file);
    else throw PlayerException();
    // TODO: zmien na unsupported type exception

    return result;
}

Player::~Player() {
    for (auto it = begin(this->playlists); it != end(this->playlists); ++it) {
        delete (*it);
    }
}

SequenceMode *createSequenceMode() {
    return new SequenceMode();
}

ShuffleMode *createShuffleMode(int seed) {
    return new ShuffleMode(seed);
}

OddEvenMode *createOddEvenMode() {
    return new OddEvenMode();
}
