#include "../HPP_files/ScoreSdl.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>


ScoreSdl::ScoreSdl(Game& game, double x, double y)
    : game(game), scorePosX(x), scorePosY(y), scoreWidth(270), scoreHeight(70) {
    
    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
    }
    
    font = TTF_OpenFont("/Users/mathisserra/Desktop/Github/B2_Laplateforme/CPPSDL/assets/minecraft_font.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    
    std::cout << "ScoreSdl constructor called" << std::endl;
}



ScoreSdl::~ScoreSdl() {
    if (font) {
        TTF_CloseFont(font);
    }
    TTF_Quit();
    std::cout << "ScoreSdl destructor called" << std::endl;
}

double ScoreSdl::posX() {
    return scorePosX;
}

double ScoreSdl::posY() {
    return scorePosY;
}

double ScoreSdl::width() {
    return scoreWidth;
}

double ScoreSdl::height() {
    return scoreHeight;
}

void ScoreSdl::updateScore() {
    int scoreActuel = game.getScore();
    int bestScore = game.getBestScore();
    currentLabel = "Score: " + std::to_string(scoreActuel) + " | Best: " + std::to_string(bestScore);
    
    
}


void ScoreSdl::resetScore() {
    currentLabel = "Score: 0 | Best: "+ std::to_string(game.getBestScore());
}

void ScoreSdl::draw(SDL_Renderer* renderer) {
    SDL_Rect scoreRect = {static_cast<int>(scorePosX), static_cast<int>(scorePosY), static_cast<int>(scoreWidth), static_cast<int>(scoreHeight)};
    SDL_Color color = {0, 0, 0, 255};
    
    SDL_Surface* surface = TTF_RenderText_Solid(font, currentLabel.c_str(), color);
    if (!surface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    } else {
        SDL_RenderCopy(renderer, texture, NULL, &scoreRect);
        SDL_DestroyTexture(texture);
    }

    SDL_FreeSurface(surface);
}
