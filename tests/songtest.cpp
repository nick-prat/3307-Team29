#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "player.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Invalid usage\n";
        return -1;
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Couldn't init SDL_INIT_AUDIO\n";
        return -1;
    }

    Player p = Player();
    Song s = Song(argv[1]);
    p.play(s);
    p.pauseUntilDonePlayer();

    return 0;
}