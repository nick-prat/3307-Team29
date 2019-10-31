#ifndef __SONG_HH
#define __SONG_HH

#include <vector>
#include <string>

#include <SDL2/SDL_mixer.h>

class Song {
public:
    Song(std::string const& filename);

    Mix_Music* getMixMusic() const;

private:
    Mix_Music* m_music;
};

#endif // __SONG_HH