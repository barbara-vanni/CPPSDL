#pragma once 


#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Score : public GameObject {
public:
    int score;
    SDL_Rect position;

    Score(int x, int y, int init_score = 0);

    void render(SDL_Renderer* renderer) override;
};


