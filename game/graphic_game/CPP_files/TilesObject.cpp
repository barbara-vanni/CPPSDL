#include "../HPP_files/TilesObject.hpp"
#include <iostream>

Tile::Tile(int x, int y, int val) : value(val) {
    position.x = x;
    position.y = y;
    position.w = 145;  // TILE_SIZE
    position.h = 145;
}

void Tile::render(SDL_Renderer* renderer) {
    SDL_Color color = getTileColor(value);
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

SDL_Color Tile::getTileColor(int value) {
    switch (value) {
        case 2: return {238, 228, 218, 255};
        case 4: return {237, 224, 200, 255};
        case 8: return {242, 177, 121, 255};
        case 16: return {245, 149, 99, 255};
        case 32: return {246, 124, 95, 255};
        case 64: return {246, 94, 59, 255};
        case 128: return {237, 207, 114, 255};
        case 256: return {237, 204, 97, 255};
        case 512: return {237, 200, 80, 255};
        case 1024: return {237, 197, 63, 255};
        case 2048: return {237, 194, 46, 255};
        default: return {204, 192, 179, 255}; // Default color
    }
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
        std::cout << "Tiles cannot be merged" << std::endl;
        return this->value; 
    }
}

Tile::~Tile() {
    std::cout << "Tile destroyed" << std::endl;
}
