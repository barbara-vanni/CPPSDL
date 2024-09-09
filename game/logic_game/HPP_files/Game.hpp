#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Board.hpp"
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
        void reset();
        void moveSdl(int inputValue);
        void moveSfml(int inputValue);
        bool checkDefeat();
        // bool checkVictory();
        void displayScore();
        void updateScore(int point);
        bool getGameOver() { return gameOver; } 
        void testDefeatScenario();

        Board* getBoard() const { return board; }

    private:
        Board* board;
        Score score;
        bool gameOver;
        int inputValue;
};



#endif // GAME_HPP