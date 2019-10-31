#ifndef __PLAYER_HH
#define __PLAYER_HH

#include "song.hpp"
#include "artist.hpp"
#include "playlist.hpp"

class Player {
public:
    Player();
    ~Player();

    void play(Song const& song);
    void play(Artist const& artist);
    void play(Playlist const& playlist);

    bool isMusicPlaying() const;
    void pauseUntilDonePlayer() const;

private:
    Song const* m_currentSong;

};

#endif // __PLAYER_HH