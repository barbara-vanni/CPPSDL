#include "../HPP_files/TilesSdl.hpp"


TilesSdl::TilesSdl(Game& game) : game(game), tileWidth(140), tileHeight(140), currentTile(nullptr), gridPosX(20), gridPosY(200) {}

TilesSdl::~TilesSdl() {}

void TilesSdl::setTile(Tiles* tile, int gridSize) {
    currentTile = tile;
}

double TilesSdl::posX() {
    if (currentTile) {
        return gridPosX + currentTile->getPosY() * tileWidth;
    }
    return 0;
}

double TilesSdl::posY() {
    if (currentTile) {
        return gridPosY + currentTile->getPosX() * tileHeight;
    }
    return 0;
}

double TilesSdl::width() {
    return tileWidth;
}

double TilesSdl::height() {
    return tileHeight;
}

void TilesSdl::drawTile(SDL_Renderer* renderer, Tiles* tile, int gridPosX, int gridPosY, int gridSize) {
    // Set tile dimensions
    setTile(tile, gridSize);

    // Draw the tile rectangle
    SDL_Rect tileRect = { static_cast<int>(posX()), static_cast<int>(posY()), tileWidth, tileHeight };
    SDL_Color tileColor = getTileColor(tile->getNumberInTile());
    SDL_SetRenderDrawColor(renderer, tileColor.r, tileColor.g, tileColor.b, tileColor.a);
    SDL_RenderFillRect(renderer, &tileRect);

    // Now render the text (number) on the tile
    int tileNumber = tile->getNumberInTile();

    if (tileNumber != 0) {
        // Load the font (make sure this is done outside the loop in a real program)
        TTF_Font* font = TTF_OpenFont("assets/font/minecraft_font.ttf", 48);  // Use appropriate font path and size
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            return;
        }

        // Create the text surface
        SDL_Color textColor = { 0, 0, 0, 255 };  // Black text
        std::string tileText = std::to_string(tileNumber);
        SDL_Surface* textSurface = TTF_RenderText_Blended(font, tileText.c_str(), textColor);

        if (textSurface) {
            // Create a texture from the text surface
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

            if (textTexture) {
                // Get the width and height of the text
                int textWidth, textHeight;
                TTF_SizeText(font, tileText.c_str(), &textWidth, &textHeight);

                // Center the text within the tile
                SDL_Rect textRect;
                textRect.x = static_cast<int>(posX()) + (tileWidth - textWidth) / 2;
                textRect.y = static_cast<int>(posY()) + (tileHeight - textHeight) / 2;
                textRect.w = textWidth;
                textRect.h = textHeight;

                // Render the text onto the tile
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

                // Clean up the texture after rendering
                SDL_DestroyTexture(textTexture);
            }

            // Free the text surface
            SDL_FreeSurface(textSurface);
        }

        // Close the font after use (In a real-world scenario, manage fonts better)
        TTF_CloseFont(font);
    }
}

SDL_Color TilesSdl::getTileColor(int value) {
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
        default: return {204, 192, 179, 255};
    }
}
