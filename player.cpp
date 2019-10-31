#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdexcept>

#include "player.hpp"

Player::Player() {
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        throw std::runtime_error("Couldn't Open Audio");
    }
}

Player::~Player() {
    Mix_CloseAudio();
}

void Player::play(Song const& song) {
    if (Mix_PlayMusic(song.getMixMusic(), -1) != -1) {
        m_currentSong = &song;
    }
}

void Player::play(Artist const& artist) {

}

void Player::play(Playlist const& playlist) {

}

void Player::pause() const {
    if (isMusicPlaying() && !isMusicPaused()) {
        Mix_PauseMusic();
    }   
}

void Player::resume() const {
    if (isMusicPlaying() && isMusicPaused()) {
        Mix_ResumeMusic();
    }
}

bool Player::isMusicPaused() const {
    return Mix_PausedMusic();
}

bool Player::isMusicPlaying() const {
    return Mix_PlayingMusic();
}

void Player::pauseUntilDonePlayer() const {
    while(Mix_PlayingMusic());
}