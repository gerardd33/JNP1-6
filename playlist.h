#ifndef JNP1_6_PLAYLIST_H
#define JNP1_6_PLAYLIST_H

#include "playable.h"
#include "mode.h"
#include "playerException.h"
#include <vector>
#include <memory>

class Playlist : public Playable, public std::enable_shared_from_this<Playlist> {
private:
    std::string name;
    std::vector<std::shared_ptr<Playable>> list;
    std::shared_ptr<Mode> mode;
public:
    void add(std::shared_ptr<Playable> playable);

    void add(std::shared_ptr<Playable> playable, int position);

    void remove();

    void remove(int position);

    void setMode(const std::shared_ptr<Mode> &mode);

    bool containsPlaylist(std::shared_ptr<Playlist> playlist);

    bool isPlaylist() override { return true; };

    void play() override;

    explicit Playlist(const std::string &name);

    ~Playlist() {
        this->mode.reset();
    };
};


#endif //JNP1_6_PLAYLIST_H
