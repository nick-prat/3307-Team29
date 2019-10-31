#ifndef __ALBUM_HH
#define __ALBUM_HH

#include <vector>

#include "song.hpp"

class Album {
public:
    std::vector<Song const*> getSongs() const;

private:
    std::vector<Song const*> m_songs;
};

#endif // __ALBUM_HH