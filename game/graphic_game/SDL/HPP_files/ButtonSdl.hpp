#ifndef BUTTONSDL_HPP
#define BUTTONSDL_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class ButtonSdl {
public:
    ButtonSdl();
    ~ButtonSdl();
    
    void drawButton(SDL_Renderer* renderer, int x, int y, int w, int h, const std::string& label);
    bool isClicked(const SDL_Event& event, int x, int y, int w, int h) const;

private:
    double buttonPosX, buttonPosY;
    double buttonWidth, buttonHeight;
    TTF_Font* font;

    void initFont();
    void cleanupFont();
};

#endif