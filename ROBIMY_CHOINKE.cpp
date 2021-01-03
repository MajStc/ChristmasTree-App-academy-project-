#include "Game.h"
#include<iostream>

int main() {

    // Init random
    std::srand(static_cast<unsigned>(time(NULL)));

    // Init game
    Game game;

    // Play some lovely, heartwarming christmas music
    sf::Music music;
    if (!music.openFromFile("Sound/BillyMack.wav")) {
        std::cout << "ERROR: couldn't open music file" << "\n";
    }
    music.play();

    //Main Loop:
    while (game.running()) {
       game.update();
       game.render();
    }

    // End
    return 0;
}