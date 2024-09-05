#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

class Input {
    public:
        Input();
        ~Input();

        int getInput();
};

#endif 


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
        bool checkDefeat();
        bool checkVictory();
        void displayScore();
        void updateScore(int point);
        bool getGameOver() { return gameOver; } 
        void testDefeatScenario();

    private:
        Board* board;
        Score score;
        bool gameOver;
};



#endif // GAME_HPP
