#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../../graphic_game/HPP_files/Grid.hpp"
#include "../../graphic_game/HPP_files/Window.hpp"
#include "Board.hpp"
#include "Input.hpp"
#include <SDL2/SDL.h>


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
        Window window;
        Board* board;
        Grid* grid;
        Score score;
        bool gameOver;
        SDL_Renderer* renderer = window.getRenderer();
        
};



#endif // GAME_HPP