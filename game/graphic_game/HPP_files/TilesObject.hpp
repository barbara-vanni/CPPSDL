#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Tile : public GameObject {
public:
    int value;
    SDL_Rect position;
    SDL_Color color;

    Tile(int x, int y, int val);
    ~Tile();

    int getX();
    int getY();
    int getValue();


    void setX(int x);
    void setY(int y);
    void setValue(int val);


    int merge(Tile* tile);

    void render(SDL_Renderer* renderer) override;
    
};


