#ifndef BOARDSDL_HPP
#define BOARDSDL_HPP

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Tiles.hpp"

class Board {
public:
    Board(int size = 4, SDL_Renderer* renderer = nullptr);
    ~Board();

    void boardInit();
    void addRandomTile();
    void displayBoard(); // Now uses SDL for rendering

private:
    std::vector<std::vector<Tiles*>> grid;
    int size;
    SDL_Renderer* renderer;  // SDL renderer for rendering the board

    void renderTile(int x, int y, int value);  // Render a single tile
};

#endif // BOARDSDL_HPP
