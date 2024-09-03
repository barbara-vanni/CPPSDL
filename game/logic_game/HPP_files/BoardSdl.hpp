#ifndef BOARDDSL_HPP
#define BOARDDSL_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>  // Include SDL_ttf for text rendering
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
    int size;
    TTF_Font* font;  // Font for rendering text
    SDL_Color textColor;  // Color for text

    SDL_Color getTileColor(int value);
    bool initSDL_TTF();  // Initialize SDL_ttf and font
    void closeSDL_TTF();  // Close SDL_ttf and clean up font
};

#endif // BOARDDSL_HPP
