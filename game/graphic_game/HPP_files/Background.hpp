#pragma once 
#include <SDL2/SDL.h>
#include "GameObject.hpp"


class Background : public GameObject {
    public:
        Background();
        ~Background();


        double setPosX(double x) override;
        double setPosY(double y) override;
        int setCellSize(int size) override;



        void draw(SDL_Renderer* renderer);

    private:
        SDL_Rect rect;
        SDL_Color color;
};
