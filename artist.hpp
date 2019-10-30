#ifndef __ARTIST_HH
#define __ARTIST_HH

#include <vector>

#include "album.hpp"

class Artist {
public:
    void addAlbum(Album const * album);

private:
    std::vector<Album const *> m_albums;
};

#endif // __ARTIST_HH