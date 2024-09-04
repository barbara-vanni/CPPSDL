#include <SDL2/SDL.h>
#include <iostream>
#include "game/logic_game/HPP_files/Game.hpp"
#include "game/logic_game/HPP_files/Input.hpp"


int main() {
    // seed for random numbers
    srand(static_cast<unsigned int>(time(0)));

    // creation of the game
    Game game;

    // game.testDefeatScenario();

    game.start();


    while (game.getGameOver() == false)
    {
        game.move();
        game.displayScore();
    }


    return 0;
}
