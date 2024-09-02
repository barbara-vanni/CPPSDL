#include "../HPP_files/Tiles.hpp"
#include <iostream>

// Constructor & Destructor
Tiles::Tiles(int posX, int posY, int numberInTile) {
    this->posX = posX;
    this->posY = posY;
    this->numberInTile = numberInTile;
}

Tiles::~Tiles() {
    std::cout << "Destructor called" << std::endl;
}

// Getters
int Tiles::getPosX() {
    return posX;
}

int Tiles::getPosY() {
    return posY;
}

int Tiles::getNumberInTile() {
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