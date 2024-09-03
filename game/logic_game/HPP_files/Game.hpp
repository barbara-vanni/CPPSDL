#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Board.hpp"
#include "Input.hpp"

class Game {
    public:
        Game();
        ~Game();

        void start();
        void move();
        bool checkDefeat();
        bool checkVictory();
        void displayScore();
        bool getGameOver() { return gameOver; } 

    private:
        Board* board;
        int score;
        bool gameOver;
};



#endif // GAME_HPP