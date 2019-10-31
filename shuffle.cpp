#include <iterator>
#include <random>
#include <algorithm>

#include "shuffle.hpp"

#include "playlist.hpp"

Playlist shufflePlaylist(Playlist const& playlist) {
    auto songs = playlist.getSongs();
    decltype(songs) newSongs{};
    std::copy(std::begin(songs), std::end(songs), std::back_inserter(newSongs));

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(newSongs), std::end(newSongs), g);

    return Playlist(playlist.getName() + "_shuffled", std::move(newSongs));
}