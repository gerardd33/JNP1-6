#include "player.h"

std::shared_ptr<Playlist> Player::createPlaylist(const std::string &name) {
    return std::make_shared<Playlist>(name);
}

std::shared_ptr<Playable> Player::openFile(const File &file) {
    // TODO: jak z tymi pointerami tu, jakis smart, dynamic_cast?
    std::shared_ptr<Playable> result;
    std::string type = file.getType();

    if (type == "audio")
        result = std::make_shared<Song>(file);
    else if (type == "video")
        result = std::make_shared<Movie>(file);
    else throw PlayerException();
    // TODO: zmien na unsupported type exception

    return result;
}

std::shared_ptr<SequenceMode> createSequenceMode() {
    return std::make_shared<SequenceMode>();
}

std::shared_ptr<ShuffleMode> createShuffleMode(int seed) {
    return std::make_shared<ShuffleMode>(seed);
}

std::shared_ptr<OddEvenMode> createOddEvenMode() {
    return std::make_shared<OddEvenMode>();
}
