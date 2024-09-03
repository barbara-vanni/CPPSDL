#ifndef BOARDDSL_HPP
#define BOARDDSL_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Tiles.hpp"

class BoardSdl {
public:
    BoardSdl(int size = 4);
    ~BoardSdl();
    void boardInit();
    void addRandomTile();
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    bool okToMove();
    void renderBoard(SDL_Renderer* renderer, int cellSize);

private:
    std::vector<std::vector<Tiles*>> grid;
    int size = 4;
    SDL_Color getTileColor(int value);
};

#endif // BOARDDSL_HPP
