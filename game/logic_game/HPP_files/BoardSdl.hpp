#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "Tiles.hpp"
#include <SDL2/SDL.h>

class Board {
public:
    Board(int size = 4, SDL_Renderer* renderer = nullptr);
    ~Board();
    
    void boardInit();
    void addRandomTile();
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    bool okToMove();

    void displayBoard();
    void render();  // New method to render the board using SDL

private:
    std::vector<std::vector<Tiles*>> grid;
    int size = 4;
    SDL_Renderer* renderer;  // SDL renderer

    void renderTile(int x, int y, int value);  // Helper method to render individual tiles
};

#endif // BOARD_HPP
