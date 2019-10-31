#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "player.hpp"
#include "playlist.hpp"
#include "shuffle.hpp"

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Couldn't init SDL_INIT_AUDIO\n";
        return -1;
    }

    Player player = Player();

    std::cout << "Loading music files...\n";

    Song s1 = Song("bensound-betterdays.mp3");
    Song s2 = Song("bensound-buddy.mp3");
    Song s3 = Song("bensound-dubstep.mp3");
    Song s4 = Song("bensound-energy.mp3");
    Song s5 = Song("file_example_MP3_700KB.mp3");

    std::cout << "Creating playlist...\n";

    auto p = Playlist("Sample");

    std::cout << "Adding songs to playlist...\n";

    p.add(s1);
    p.add(s2);
    p.add(s3);
    p.add(s4);
    p.add(s5);

    std::cout << "Pring song names...\n";

    for(auto const& song : p.getSongs()) {
        std::cout << song->getName() << '\n';
    }

    std::cout << "Shuffling playlist...\n";

    auto p2 = shufflePlaylist(p);

    std::cout << "Printing shuffled song names...\n";

    for(auto const& song : p2.getSongs()) {
        std::cout << song->getName() << '\n';
    }

    std::cout << "Exiting...\n" << '\n';

    return 0;
}