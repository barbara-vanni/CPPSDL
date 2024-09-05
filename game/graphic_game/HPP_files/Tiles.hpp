#pragma once 

#include< SDL2/SDL.h>
#include "GameObject.hpp"


class Tiles : public GameObject {
    public:
        Tiles();
        ~Tiles();




        double posX(double x) override;
        double posY(double y) override;
        int size(int size) override;

        int getValue();
        void setValue(int value);
        

        void mergeTiles(SDL_Renderer* renderer, int** grid, int i, int j, int i2, int j2);
        void displayTiles(SDL_Renderer* renderer, int** grid);
        void moveTiles(SDL_Renderer* renderer, int** grid, int direction);
    
    private:
        SDL_Rect rect;
        SDL_Color color;
        int value;

};
