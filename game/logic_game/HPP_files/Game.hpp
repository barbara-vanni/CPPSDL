#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../../graphic_game/HPP_files/Grid.hpp"
#include "Input.hpp"


struct Score
{
    int scoreActuel = 0;
    int scoreMax = 0;
};

class Game {
    public:
        Game();
        ~Game();

        void start();
        void move();
        bool checkDefeat();
        bool checkVictory();
        void displayScore();
        void updateScore(int point);
        bool getGameOver() { return gameOver; } 
        // Board* getBoard() { return board; }
        // void testDefeatScenario();

    private:
        Grid* grid;
        Score score;
        bool gameOver;
};



#endif // GAME_HPP
