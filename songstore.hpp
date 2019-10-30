#ifndef __SONGSTORE_HH
#define __SONGSTORE_HH

#include <string>
#include <vector>

#include "song.hpp"
#include "artist.hpp"

class SongStore {
public:
    SongStore(std::string const& filename);

    Song& getSong(std::string const& song);
    Artist& getArtist(std::string const& song);

private:
    std::vector<Artist> m_artists;
    std::vector<Song> m_songs;
};

#endif // __SONGSTORE_HH