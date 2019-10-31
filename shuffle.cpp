#include <iterator>
#include <random>
#include <algorithm>

#include "shuffle.hpp"

#include "playlist.hpp"

Playlist shufflePlaylist(Playlist const& playlist) {
    auto songs = playlist.getSongs();
    auto newSongsVector = std::vector<Song const*>();
    std::copy(std::begin(songs), std::end(songs), std::back_inserter(newSongsVector));

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(newSongsVector), std::end(newSongsVector), g);

    auto newSongsList = std::list<Song const*>();
    std::copy(std::begin(newSongsVector), std::end(newSongsVector), std::back_inserter(newSongsList));

    return Playlist(playlist.getName() + "_shuffled", std::move(newSongsList));
}