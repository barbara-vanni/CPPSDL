#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../../graphic_game/HPP_files/Grid.hpp"
#include "../../graphic_game/HPP_files/Window.hpp"
#include "../../graphic_game/HPP_files/Background.hpp"
#include "../../graphic_game/HPP_files/Tiles.hpp"
#include "Board.hpp"
#include "Input.hpp"
#include <SDL2/SDL.h>

struct Score {
    int scoreActuel = 0;
    int scoreMax = 0;
}; // Assuming Input.hpp defines the Input class

class Game {
public:
    Game();
    ~Game();
    void start();
    
private:
    void move();
    bool checkDefeat();
    void displayScore();
    void updateScore(int points);
    void render();
    
    Grid* grid;
    Window* window;
    SDL_Renderer* renderer;
    bool gameOver;
    Score score;
    Background* background;
    Tiles* tiles; // Assumed to be used for displaying tile values
};

#endif // GAME_HPP