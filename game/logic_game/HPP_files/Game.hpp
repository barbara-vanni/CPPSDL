#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include "Board.hpp"
#include "Input.hpp"


struct Score
{
    int scoreActuel = 0;
    int scoreMax = 0;

    void loadScore()
    {
        std::ifstream file("score.txt");
        if (file.is_open())
        {
            file >> scoreMax;
            file.close();
        }
        else
        {
            std::cerr << "Failed to open file" << std::endl;
        }
    }

    void saveScore()
    {
        std::ofstream file("score.txt");
        if (file.is_open())
        {
            file << scoreMax;
            file.close();
        }
        else
        {
            std::cerr << "Failed to open file" << std::endl;
        }
    }
};

class Game {
    public:
        Game();
        ~Game();

        void start();
        void move();
        void moveSfml(int inputValue);
        bool checkDefeat();
        // bool checkVictory();
        void displayScore();
        void updateScore(int point);
        int getScoreActuel() { return score.scoreActuel; }
        int getBestScore() { return score.scoreMax; }
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