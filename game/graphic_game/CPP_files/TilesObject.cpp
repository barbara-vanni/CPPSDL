#include "../HPP_files/TilesObject.hpp"

Tile::Tile(int x, int y, int val) : value(val) {
    position.x = x;
    position.y = y;
    position.w = 100;  // TILE_SIZE
    position.h = 100;
    color = {255, 255, 255, 255};  // Default white color
}

void Tile::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &position);
}
