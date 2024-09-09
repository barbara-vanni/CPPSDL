#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>  // Include SDL_ttf for text rendering
#include "../GameObject.hpp"
#include <string>

class ButtonSdl : public GameObject {
public:
    ButtonSdl();
    ~ButtonSdl();

    double posX()  override;
    double posY() override;
    double width() override;
    double height()  override;

    // Updated method signature with font and label parameters
    void drawButton(SDL_Renderer* renderer, int x, int y, int w, int h, TTF_Font* font = nullptr, const std::string& label = "");
    bool isClicked(const SDL_Event& event, int x, int y, int w, int h) const;

private:
    double buttonPosX;
    double buttonPosY;
    double buttonWidth;
    double buttonHeight;
};
