
// Ian Bejarano - Group 29

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include <vector>

#include "song.hpp"

class Playlist {
    private:
        string name; 
        int num_songs; 
        std::vector<Song const *> playlist;
    
    public:
        // constructor 
        Playlist(string name); 
        
        // playlist name methods
        string getName();
        
        // get  the songs in the playlist
        vector<Song const *> const& getPlaylist() {};
        
        // add to the playlist methods 
        void add(Song const * song);
        void add(Album const * album);
        void add(Playlist const * playlist);
        
        void delete(Song song);
        
        void place_order(Song const * song, int placement);
}

#endif PLAYLIST_HPP