#include <iostream>
#include "game/logic_game/HPP_files/Game.hpp"
#include "game/logic_game/HPP_files/Input.hpp"


int main() {
    // seed for random numbers
    srand(static_cast<unsigned int>(time(0)));


    // creation of the game
    Game game;

    game.start();

    
    Input input;
    
    while (true) {
        int inputValue = input.getInput();  
        if (inputValue == 27) {
            break;
        }
    }


    // while (!game.checkDefeat() && !game.checkVictory())
    // {
    //     game.move();
    // }

    game.displayScore();

    return 0;
}
