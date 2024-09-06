#pragma once
#include "../GameObject.hpp"
#include "../../logic_game/HPP_files/Tiles.hpp"
#include "TilesSdl.hpp"
#include "../../logic_game/HPP_files/Board.hpp"
#include <SDL2/SDL.h>
#include <vector>

class Grid : public GameObject {
public:
    Board *board;                     // The board holds the logic for the tiles
    std::vector<TilesSdl*> tiles;     // Vector to hold SDL representations of tiles
    Grid(double x, double y, double w, double h, int rows, int cols);
    double posX() override;
    double posY() override;
    double width() override;
    double height() override;
    void draw(SDL_Renderer* renderer);
    ~Grid() override;

private:
    SDL_Color color;
    double x;
    double y;
    double w;
    double h;
    int rows;
    int cols;
};
