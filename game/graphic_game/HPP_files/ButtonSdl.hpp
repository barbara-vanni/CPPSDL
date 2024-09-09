#pragma once 
#include <SDL2/SDL.h>
#include "../GameObject.hpp"


class ButtonSdl : public GameObject {
    public :
        ButtonSdl();
        ~ButtonSdl();
        double posX() override;
        double posY() override;
        double width() override;
        double height() override;

        void drawButton(SDL_Renderer* renderer, int x, int y, int w, int h);
        bool isClicked(SDL_Event event, int x, int y, int w, int h);

    private :
        double buttonPosX;
        double buttonPosY;
        double buttonWidth;
        double buttonHeight;
};
