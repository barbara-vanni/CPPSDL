#ifndef SCORESDL_HPP
#define SCORESDL_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Game; // Forward declaration

class ScoreSdl {
public:
    ScoreSdl(Game &game, double x, double y, const std::string& label);
    ~ScoreSdl();
    
    void updateActualScore(int score);
    void updateBestScore(int score);
    void draw(SDL_Renderer* renderer);
    void drawDefeat(SDL_Renderer* renderer);

private:
    Game &game;
    double scorePosX, scorePosY;
    std::string labelText, currentLabel;
    TTF_Font* font;

    SDL_Surface* labelSurface;
    SDL_Texture* labelTexture;
    SDL_Surface* scoreSurface;
    SDL_Texture* scoreTexture;

    void initFont();
    void cleanupFont();
    void renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color, SDL_Rect& rect, SDL_Texture*& texture, SDL_Surface*& surface);
};

#endif // SCORESDL_HPP