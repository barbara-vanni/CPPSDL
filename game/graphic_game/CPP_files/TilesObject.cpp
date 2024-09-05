#include "../HPP_files/TilesObject.hpp"
#include <iostream>

Tile::Tile(int x, int y, int val) : value(val) {
    position.x = x;
    position.y = y;
    position.w = 145;  // TILE_SIZE
    position.h = 145;
    if (value == 2) {
        color = {238, 228, 218, 255};  // Light beige color for 2 tile
    } else if (value == 4) {
        color = {237, 224, 200, 255};  // Light orange color for 4 tile
    } else if (value == 8) {
        color = {242, 177, 121, 255};  // Dark orange color for 8 tile
    } else if (value == 16) {
        color = {245, 149, 99, 255};  // Light brown color for 16 tile
    } else if (value == 32) {
        color = {246, 124, 95, 255};  // Dark brown color for 32 tile
    } else if (value == 64) {
        color = {246, 94, 59, 255};  // Light red color for 64 tile
    } else if (value == 128) {
        color = {237, 207, 114, 255};  // Dark yellow color for 128 tile
    } else if (value == 256) {
        color = {237, 204, 97, 255};  // Light yellow color for 256 tile
    } else if (value == 512) {
        color = {237, 200, 80, 255};  // Dark yellow color for 512 tile
    } else if (value == 1024) {
        color = {237, 197, 63, 255};  // Light orange color for 1024 tile
    } else if (value == 2048) {
        color = {237, 194, 46, 255};  // Dark orange color for 2048 tile
    } else {
        color = {0,0,0, 255};  // Default white color
    }
}

void Tile::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &position);
}



int Tile::getX() {
    return position.x;
}

int Tile::getY() {
    return position.y;
}

int Tile::getValue() {
    return value;
}

void Tile::setX(int x) {
    this->position.x = x;
}

void Tile::setY(int y) {
    this->position.y = y;
}

void Tile::setValue(int val) {
    this->value = val;
}

int Tile::merge(Tile* tile) {
    if (this->value == tile->getValue()) {
        this->value += tile->getValue();
        tile->setValue(0);  
        return this->value;
    } else {
        std::cout << "Tiles cannot merged" << std::endl;
        return this->value; 
    }
}



Tile::~Tile() {
    std::cout << "Tile destroyed" << std::endl;
}



