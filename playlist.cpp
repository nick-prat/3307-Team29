// Ian Bejarano - Group 29
#include <algorithm>

#include "playlist.hpp"

// Constructor implementation

Playlist::Playlist(std::string const& name)
: m_name(name) {}

Playlist::Playlist(std::string const& name, std::list<Song const*>&& songs)
: m_name(name), m_songs(songs) {}

// Method implementations 

std::string Playlist::getName() const {
    return m_name; 
} 

// return a vector of the playlist
std::list<Song const *> const& Playlist::getSongs() const {
    return m_songs; 
}

// add an individual song
void Playlist::add(Song const& song) {
    m_songs.push_back(&song);
}

// add a whole album all at once
void Playlist::add(Album const& album) {
    std::vector<Song const *> const& album_vector = album.getSongs(); 
    
    for(int i = 0; album_vector.size(); i++) {
        m_songs.push_back(album_vector[i]); 
    }
}

// add a whole other playlist at once
void Playlist::add(Playlist const& playlist) {
    auto const& songs = playlist.getSongs(); 
    
    for(auto song : songs) {
        m_songs.push_back(song);
    }
}

// delete a song from the playlist
void Playlist::remove(Song const& song) {
    m_songs.remove_if([&song](auto value) {
        return song == *value;
    });
}

// change the position of the song in the playlist's track listing 
void Playlist::placeOrder(Song const& song, int placement) {
    remove(song); // deletes the song at its current position

    auto iter = std::begin(m_songs);
    for(int i = 0; i < placement && iter != std::end(m_songs); i++) iter++; // search for iter at begin + placement
    m_songs.insert(iter, &song);
}

