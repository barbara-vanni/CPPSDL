#include <iostream>
#include "game/logic_game/HPP_files/Game.hpp"


int main() {
 
    srand(static_cast<unsigned int>(time(0)));

    // creation of the game
    Game game;

    game.start();

    // while (!game.checkDefeat() && !game.checkVictory())
    // {
    //     game.move();
    // }

    game.displayScore();

    return 0;
}
