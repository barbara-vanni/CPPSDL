#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Tile : public GameObject {
public:
    int value;
    SDL_Rect position;
    SDL_Color color;

    Tile(int x, int y, int val);

    void render(SDL_Renderer* renderer) override;
};


