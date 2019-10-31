#include <iostream>
#include <chrono>
#include <thread>

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

    std::chrono::seconds timespan(5);
    
    Player p = Player();
    Song s = Song(argv[1]);

    std::cout << "Playing for 5s\n";
    p.play(s);
    std::this_thread::sleep_for(timespan);

    std::cout << "Pausing for 5s\n";
    p.pause();
    std::this_thread::sleep_for(timespan);

    std::cout << "Resuming for 5s\n";
    p.resume();
    std::this_thread::sleep_for(timespan);


    std::cout << "Exiting...\n";

    return 0;
}