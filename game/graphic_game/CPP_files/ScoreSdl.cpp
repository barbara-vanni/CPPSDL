#include "../HPP_files/ScoreSdl.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

ScoreSdl::ScoreSdl(Game &game, double x, double y)
    : game(game), scorePosX(x), scorePosY(y)
{

    if (TTF_Init() == -1)
    {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
    }

    font = TTF_OpenFont("assets/font/minecraft_font.ttf", 24);
    if (!font)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    std::cout << "ScoreSdl constructor called" << std::endl;
}

ScoreSdl::~ScoreSdl()
{
    if (font)
    {
        TTF_CloseFont(font);
    }
    TTF_Quit();
    std::cout << "ScoreSdl destructor called" << std::endl;
}

double ScoreSdl::posX()
{
    return scorePosX;
}

double ScoreSdl::posY()
{
    return scorePosY;
}

double ScoreSdl::width()
{
    return 0;
}

double ScoreSdl::height()
{
    return 0;
}

void ScoreSdl::updateActualScore(int score)
{

    int scoreActuel = game.getScoreActuel();

    currentLabel = (std::to_string(scoreActuel));
}

void ScoreSdl::updateBestScore(int score)
{

    int bestScore = game.getBestScore();

    currentLabel = (std::to_string(bestScore));
}


void ScoreSdl::draw(SDL_Renderer *renderer)
{

    if (currentLabel.empty()) {
        std::cerr << "Error: currentLabel is empty, cannot render text." << std::endl;
        return;
    }

    SDL_Color color = {0, 0, 0, 255};


    SDL_Surface *surface = TTF_RenderText_Solid(font, currentLabel.c_str(), color);
    if (!surface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }


    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    }
    else {

        SDL_Rect scoreRect = {static_cast<int>(scorePosX), static_cast<int>(scorePosY), surface->w, surface->h};

        SDL_RenderCopy(renderer, texture, NULL, &scoreRect);

        SDL_DestroyTexture(texture);
    }

    SDL_FreeSurface(surface);
}


void ScoreSdl::drawDefeat(SDL_Renderer *renderer)
{
    std::string defeat = "Game Over";
    SDL_Color color = {0, 0, 0, 255};

    SDL_Surface *surface = TTF_RenderText_Solid(font, defeat.c_str(), color);
    if (!surface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    }
    else {

        SDL_Rect scoreRect = {static_cast<int>(scorePosX), static_cast<int>(scorePosY), surface->w, surface->h};

        SDL_RenderCopy(renderer, texture, NULL, &scoreRect);

        SDL_DestroyTexture(texture);
    }

    SDL_FreeSurface(surface);
}

