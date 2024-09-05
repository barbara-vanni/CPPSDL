#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Button : public GameObject {
public:
    SDL_Rect position;
    SDL_Color color;
    std::string label;

    Button(int x, int y, int w, int h, std::string lbl);

    void render(SDL_Renderer* renderer) override;
};
