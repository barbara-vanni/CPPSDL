#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Background : public GameObject {
public:
    SDL_Color color;

    Background();
    void render(SDL_Renderer* renderer) override;
};


