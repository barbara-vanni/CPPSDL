//Tiles.cpp

#include "../HPP_files/BoardSdl.hpp"
#include "../HPP_files/Tiles.hpp"
#include <iostream>

/*
    This class is responsible for creating the tiles that will be used in the game.
    Each tile has a position in the game board and a number that will be used to merge with other tiles.
    The tiles can be merged if they have the same number.
*/

// Constructor & Destructor
Tiles::Tiles(int posX, int posY, int numberInTile)
    : GameObject(posX, posY, 100, 100), // Initialize the base class with default width and height
      posX(posX),
      posY(posY),
      numberInTile(numberInTile) {
    // Constructor body if needed
}

Tiles::~Tiles() {
    std::cout << "Destructor called" << std::endl;
}

// Getters
int Tiles::getPosX() const {
    return posX;
}

int Tiles::getPosY()  const {
    return posY;
}

int Tiles::getNumberInTile()  const {
    return numberInTile;
}

// Setters
void Tiles::setPosX(int posX) {
    this->posX = posX;
}

void Tiles::setPosY(int posY) {
    this->posY = posY;
}

void Tiles::setNumberInTile(int numberInTile) {
    this->numberInTile = numberInTile;
}

// Other methods
int Tiles::mergeTilesNumbers(Tiles* tile) {
    if (this->numberInTile == tile->getNumberInTile()) {
        this->numberInTile += tile->getNumberInTile();
        tile->setNumberInTile(0);  
        return this->numberInTile;
    } else {
        std::cout << "Tiles cannot merged" << std::endl;
        return this->numberInTile; 
    }
}

void Tiles::render(SDL_Renderer* renderer, int cellSize, BoardSdl* board) const {
    SDL_Rect rect;
    rect.x = posX * cellSize;
    rect.y = posY * cellSize;
    rect.w = cellSize;
    rect.h = cellSize;

    // Set tile color based on its value
    SDL_Color tileColor = board->getTileColor(numberInTile);
    SDL_SetRenderDrawColor(renderer, tileColor.r, tileColor.g, tileColor.b, tileColor.a);
    SDL_RenderFillRect(renderer, &rect);

    // If the tile has a number, render the number as text
    if (numberInTile > 0) {
        // Render number in tile
        // (Assuming you have a function to render text)
    }
}

//Tiles.cpp
