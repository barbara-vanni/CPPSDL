// Tile.cpp
#include "../HPP_files/Tiles.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

Tile::Tile(int posX, int posY, int numberInTile) : posX(posX), posY(posY), numberInTile(numberInTile) {}

Tile::~Tile() {}

int Tile::getPosX() const { return posX; }
int Tile::getPosY() const { return posY; }
int Tile::getNumberInTile() const { return numberInTile; }
void Tile::setPosX(int posX) { this->posX = posX; }
void Tile::setPosY(int posY) { this->posY = posY; }
void Tile::setNumberInTile(int numberInTile) { this->numberInTile = numberInTile; }

void Tile::draw(SDL_Renderer* renderer) const {
    // Define tile size and colors
    const int TILE_SIZE = 150;
    SDL_Rect rect = { posX * TILE_SIZE, posY * TILE_SIZE, TILE_SIZE, TILE_SIZE };
    
    SDL_Color color;
    switch (numberInTile) {
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
    
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    // Render the number in the tile
   
    TTF_Font* font = TTF_OpenFont("assets/minecraft_font.ttf", 50); // Adjust font path and size
    if (font) {
        std::string text = std::to_string(numberInTile);
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), { 0, 0, 0 }); // Black text
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textWidth = textSurface->w;
        int textHeight = textSurface->h;
        SDL_Rect textRect = { posX * TILE_SIZE + (TILE_SIZE - textWidth) / 2, posY * TILE_SIZE + (TILE_SIZE - textHeight) / 2, textWidth, textHeight };

        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
        TTF_CloseFont(font);
    }
}
