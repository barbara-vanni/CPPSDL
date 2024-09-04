// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Score.hpp"
#include <SDL2/SDL.h>

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
    bool getGameOver() const { return gameOver; }
    void displayBoard(SDL_Renderer* renderer, int cellSize) const;

private:
    Board* board;
    // Score score;
    bool gameOver;
};

#endif // GAME_HPP
