#pragma once 

#include<SDL2/SDL.h>
#include "GameObject.hpp"



class Grid;


class Tiles : public GameObject {
    public:
        Tiles();
        ~Tiles();




        double setPosX(double x) override;
        double setPosY(double y) override;
        int setCellSize(int size) override;


        
        int getValue();
        void setValue(int value);
        

        int mergeTiles(Tiles* tile);
        void displayTiles(SDL_Renderer* renderer, const std::vector<std::vector<Tiles*>>& grid, const Grid& gridObject);
        void moveTiles(SDL_Renderer* renderer, int** grid, int direction);
    
    private:
        SDL_Rect rect;
        SDL_Color color;
        int value;

};
