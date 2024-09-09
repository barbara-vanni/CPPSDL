#include "../HPP_files/ButtonSdl.hpp"
#include "../HPP_files/ButtonSdl.hpp"
#include <iostream>

ButtonSdl::ButtonSdl()
{
    buttonPosX = 0;
    buttonPosY = 0;
    buttonWidth = 0;
    buttonHeight = 0;
}

ButtonSdl::~ButtonSdl() {}

double ButtonSdl::posX()
{
    return buttonPosX;
}

double ButtonSdl::posY()
{
    return buttonPosY;
}

double ButtonSdl::width()
{
    return buttonWidth;
}

double ButtonSdl::height()
{
    return buttonHeight;
}

void ButtonSdl::drawButton(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    buttonPosX = x;
    buttonPosY = y;
    buttonWidth = w;
    buttonHeight = h;

    SDL_Rect button = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &button);
}

bool ButtonSdl::isClicked(SDL_Event event, int x, int y, int w, int h)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (event.type == SDL_MOUSEBUTTONDOWN && mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h)
    {
        return true;
        std::cout << "Button clicked" << std::endl;
    }

    return false;
}

