#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include "Board.hpp"
#include "Input.hpp"

/*
This class is the main class of the game
This class will contain the logic of the game
This class will also contain the score of the game
*/ 

struct Score
{
    int actualScore = 0; 
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
        void reset();
        void moveSdl(int inputValue);
        void moveSfml(int inputValue);
        bool checkDefeat();
        void displayScore();
        void updateScore(int point);
        int getActualScore() { return score.actualScore; } 
        int getBestScore() { return score.scoreMax; }

        Board* getBoard() const { return board; }

    private:
        Board* board;
        Score score;
        bool gameOver;
        int inputValue;
        void playMoveSound();
};



#endif