#include "../HPP_files/ScoreSdl.hpp"
#include <iostream>

/*This class display the Score and the game over message
*/
ScoreSdl::ScoreSdl(Game &game, double x, double y, const std::string& label)
    : game(game), scorePosX(x), scorePosY(y), labelText(label), font(nullptr),
      labelSurface(nullptr), labelTexture(nullptr), scoreSurface(nullptr), scoreTexture(nullptr) {
    initFont(); // Initialize font here
}

ScoreSdl::~ScoreSdl() {
    cleanupFont(); // Cleanup font 

    if (labelSurface) SDL_FreeSurface(labelSurface); // Free the surface
    if (labelTexture) SDL_DestroyTexture(labelTexture);
    if (scoreSurface) SDL_FreeSurface(scoreSurface);
    if (scoreTexture) SDL_DestroyTexture(scoreTexture);
}
// load the font
void ScoreSdl::initFont() {
    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }

    font = TTF_OpenFont("assets/font/minecraft_font.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

void ScoreSdl::cleanupFont() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    
}

void ScoreSdl::updateActualScore(int score) {
    currentLabel = std::to_string(score);
}

void ScoreSdl::updateBestScore(int score) {
    currentLabel = std::to_string(score);
}

void ScoreSdl::draw(SDL_Renderer* renderer) {
    // Draw the label text (e.g., "Score")
    if (!labelText.empty()) {
        SDL_Color labelColor = {0, 0, 0, 255}; 
        labelSurface = TTF_RenderText_Solid(font, labelText.c_str(), labelColor);
        labelTexture = SDL_CreateTextureFromSurface(renderer, labelSurface);

        SDL_Rect labelRect = {static_cast<int>(scorePosX), static_cast<int>(scorePosY), labelSurface->w, labelSurface->h};
        SDL_RenderCopy(renderer, labelTexture, NULL, &labelRect);

        SDL_FreeSurface(labelSurface);
        SDL_DestroyTexture(labelTexture);
    }

    // Draw the current score
    if (!currentLabel.empty()) {
        SDL_Color scoreColor = {0, 0, 0, 255}; 
        scoreSurface = TTF_RenderText_Solid(font, currentLabel.c_str(), scoreColor);
        scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

        SDL_Rect scoreRect = {static_cast<int>(scorePosX), static_cast<int>(scorePosY + 40), scoreSurface->w, scoreSurface->h};
        SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

        SDL_FreeSurface(scoreSurface);
        SDL_DestroyTexture(scoreTexture);
    }
}

void ScoreSdl::drawDefeat(SDL_Renderer* renderer) {
    // Define the white background rectangle
    SDL_Rect backgroundRect = {0, 400, 600, 150}; // Full width of 600px, height of 150px

    // Create the game over text
    SDL_Color textColor = {255, 0, 0, 255}; 
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Game Over", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    // Define the text rectangle
    SDL_Rect textRect = {152, 390, 300, 150}; // Centered horizontally, same height as the text surface

    // Draw the white background behind the text
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &backgroundRect);

    // Draw the text on top of the background
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Clean up
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}