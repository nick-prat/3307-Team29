// Ian Bejarano - Group 29

#include "playlist.hpp"

// Constructor implementation
Playlist::Playlist(string name) {
    this.name = name;
}

// Method implementations 

string Playlist::getName() {
    return name; 
} 

// return a vector of the playlist
vector<Song const *> const& Playlist::getPlaylist() {
    return playlist; 
}

// add an individual song
void Playlist::add(Song const * song) {
    playlist.push_back(song);
    num_songs++;
}

// add a whole album all at once
void Playlist::add(Album const * album) {
    vector<Song const *> const& album_vector = album.getAlbum(); 
    
    for(int i = 0; album_vector.size(); i++) {
        playlist.push_back(album_vector[i]); 
    }
    
    num_songs += album_vector.size(); 
}

// add a whole other playlist at once
void Playlist::add(Playlist const * playlist) {
    vector<Song const *> const& playlist_vector = playlist.getPlaylist(); 
    
    for(int i = 0; playlist_vector.size(); i++) {
        playlist.push_back(playlist_vector[i]); 
    }
    
    num_songs += playlist_vector.size(); 
}

// delete a song from the playlist
void Playlist::delete(Song const * song) {
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

