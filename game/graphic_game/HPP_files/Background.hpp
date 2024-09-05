#pragma once 
#include <SDL2/SDL.h>
#include "GameObject.hpp"


class Background : public GameObject {
    public:
        Background();
        ~Background();


        double posX(double x) override;
        double posY(double y) override;
        int size(int size) override;



        void draw(SDL_Renderer* renderer);

    private:
        SDL_Rect rect;
        SDL_Color color;
};
