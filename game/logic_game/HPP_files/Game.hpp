#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "BoardSdl.hpp"
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
    bool getGameOver() const { return gameOver; } 

private:
    BoardSdl* board;  // Changed from Board* to BoardSdl*
    int score;
    bool gameOver;
};

#endif // GAME_HPP
