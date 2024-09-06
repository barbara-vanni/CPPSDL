#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../HPP_files/TilesSdl.hpp"

// Function to get color based on tile number
SDL_Color getTileColor(int number) {
    switch (number) {
        case 2:   return {238, 228, 218, 255}; // Light Tan
        case 4:   return {237, 224, 200, 255}; // Light Orange
        case 8:   return {242, 177, 121, 255}; // Light Red
        case 16:  return {245, 149, 99, 255};  // Light Pink
        case 32:  return {246, 124, 95, 255};  // Light Purple
        case 64:  return {246, 94, 59, 255};   // Light Blue
        case 128: return {237, 207, 114, 255}; // Light Green
        case 256: return {237, 204, 97, 255};  // Light Teal
        case 512: return {237, 200, 80, 255};  // Light Cyan
        case 1024: return {237, 197, 63, 255}; // Light Yellow
        case 2048: return {237, 194, 46, 255}; // Light Gold
        default: return {204, 192, 179, 255};  // Light Gray for other numbers
    }
}

TilesSdl::TilesSdl(double x, double y, double w, double h, int numberInTile) {
    // Properly construct the Tiles object by passing the correct arguments
    this->tiles = new Tiles(static_cast<int>(x), static_cast<int>(y), numberInTile);

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    color = getTileColor(numberInTile); // Set color based on tile number

    // Load font (ensure the font path is valid)
    font = TTF_OpenFont("/Users/mathisserra/Desktop/Github/B2_Laplateforme/CPPSDL/assets/minecraft_font.ttf", 40);  
    if (font == nullptr) {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
    }
}

TilesSdl::~TilesSdl() {
    if (font) {
        TTF_CloseFont(font);
    }
    if (tiles) {
        delete tiles;
    }
    std::cout << "TilesSdl destroyed" << std::endl;
}

double TilesSdl::posX() {
    return x;
}

double TilesSdl::posY() {
    return y;
}

double TilesSdl::width() {
    return w;
}

double TilesSdl::height() {
    return h;
}

void TilesSdl::draw(SDL_Renderer* renderer) {
    if (font == nullptr) {
        std::cerr << "Font is not initialized. Skipping draw." << std::endl;
        return;
    }

    // Draw the tile rectangle with the appropriate color
    SDL_Rect rect = {static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h)};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    // Get the text to display (tile number)
    std::string text = std::to_string(tiles->getNumberInTile());

    // Render the text
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {255, 255, 255, 255}); // White text
    if (surface == nullptr) {
        std::cerr << "Error creating surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    // Calculate text size and position it at the center of the tile
    int textWidth = 0, textHeight = 0;
    TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);

    SDL_Rect textRect = {
        static_cast<int>(x + (w - textWidth) / 2),
        static_cast<int>(y + (h - textHeight) / 2),
        textWidth,
        textHeight
    };

    // Render the text inside the tile
    SDL_RenderCopy(renderer, texture, nullptr, &textRect);

    // Free resources
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
