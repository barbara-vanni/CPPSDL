#pragma once
#include <SDL2/SDL.h>
#include "GameObject.hpp"
// #include "game/logic_game/HPP_files/Input.hpp"


class Grid : public GameObject {
    public:
        Grid();
        ~Grid();


        double posX(double x) override;
        double posY(double y) override;
        int size(int size) override;


        void displayGrid(SDL_Renderer* renderer);
        void checkDefeat(SDL_Renderer* renderer, int** grid);
        void addNewTile(SDL_Renderer* renderer, int** grid);
        void okToMove(SDL_Renderer* renderer, int** grid);


        SDL_Rect rect;

    private :
        SDL_Color color;


};

