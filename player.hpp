#ifndef __PLAYER_HH
#define __PLAYER_HH

#include "song.hpp"
#include "artist.hpp"
#include "playlist.hpp"

class Player {
public:
    void play(Song const& song);
    void play(Artist const& artist);
    void play(Playlist const& playlist);
};

#endif // __PLAYER_HH