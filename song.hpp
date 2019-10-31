#ifndef __SONG_HH
#define __SONG_HH

#include <vector>
#include <string>

#include <SDL2/SDL_mixer.h>

class Song {
public:
    Song(std::string const& filename);

    bool operator==(Song const& song) const;

    std::string const& getName() const;
    Mix_Music* getMixMusic() const;

private:
    std::string m_name;
    Mix_Music* m_music;
};

#endif // __SONG_HH