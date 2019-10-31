#include "album.hpp"

std::vector<Song const*> Album::getSongs() const {
    return m_songs;
}