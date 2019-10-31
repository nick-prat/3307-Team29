// Ian Bejarano - Group 29
#include <algorithm>

#include "playlist.hpp"

// Constructor implementation
Playlist::Playlist(std::string const& name)
: m_name(name), m_numSongs(0) {}

// Method implementations 

std::string Playlist::getName() const {
    return m_name; 
} 

// return a vector of the playlist
std::vector<Song const *> const& Playlist::getSongs() const {
    return m_playlist; 
}

// add an individual song
void Playlist::add(Song const& song) {
    m_playlist.push_back(&song);
    m_numSongs++;
}

// add a whole album all at once
void Playlist::add(Album const& album) {
    std::vector<Song const *> const& album_vector = album.getSongs(); 
    
    for(int i = 0; album_vector.size(); i++) {
        m_playlist.push_back(album_vector[i]); 
    }
    
    m_numSongs += album_vector.size(); 
}

// add a whole other playlist at once
void Playlist::add(Playlist const& playlist) {
    std::vector<Song const *> const& playlist_vector = playlist.getSongs(); 
    
    for(int i = 0; playlist_vector.size(); i++) {
        m_playlist.push_back(playlist_vector[i]); 
    }
    
    m_numSongs += playlist_vector.size(); 
}

// delete a song from the playlist
void Playlist::remove(Song const& song) {
    auto iter = std::find_if(std::begin(m_playlist), std::end(m_playlist), song);
    if (iter == std::end(m_playlist)) {
        return;
    }
    
    for(int i = 0; i < playlist.size(); i++) {
        if(playlist[i].compare(song.getName())) {
            playlist.erase(i)
        }
    }
    
    num_songs--; 
}

// change the position of the song in the playlist's track listing 
void Playlist::place_order(Song const * song, int placement) {
    delete(song); // deletes the song at its current position
    num_songs++; // add to the number of songs since delete() reduces the count

    // place the song at its new position
    std::vector<Song const *>::iterator it; 
    it = playlist.insert(it, placement);
    
}

