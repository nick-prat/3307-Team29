#include <stdexcept>

#include "song.hpp"

Song::Song(std::string const& filename) {
    m_music = Mix_LoadMUS(filename.c_str());
    if (m_music == nullptr) {
        throw std::runtime_error("Couldn't open file " + filename);
    }
}

Mix_Music* Song::getMixMusic() const {
    return m_music;
}