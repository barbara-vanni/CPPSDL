#pragma once 
#include "../GameObject.hpp"
#include <SDL2/SDL.h>


class Background : public GameObject {
public:
    Background(double x, double y, double w, double h);
    double posX() override;
    double posY() override;
    double width() override;
    double height() override;
    void draw(SDL_Renderer* renderer);
    ~Background() override;
private:
    SDL_Color color;
    double x;
    double y;
    double w;
    double h;
};
