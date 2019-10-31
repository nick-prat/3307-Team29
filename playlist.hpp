
// Ian Bejarano - Group 29

#ifndef __PLAYLIST_HPP
#define __PLAYLIST_HPP

#include <string>
#include <vector>

#include "song.hpp"
#include "album.hpp"

class Playlist {
public:
    // constructor 
    Playlist(std::string const& name); 
    
    // playlist name methods
    std::string getName() const;
    
    // get  the songs in the playlist
    std::vector<Song const *> const& getSongs() const;
    
    // add to the playlist methods 
    void add(Song const& song);
    void add(Album const& album);
    void add(Playlist const& playlist);
    
    void remove(Song const& song);
    
    void place_order(Song const& song, int placement);

private:
    std::string m_name; 
    int m_numSongs; 
    std::vector<Song const *> m_playlist;
};

#endif // __PLAYLIST_HPP