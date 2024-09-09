#ifndef GRIDSdl_HPP
#define GRIDSdl_HPP

#include "TilesSdl.hpp"
#include "../GameObject.hpp"
#include "../../logic_game/HPP_files/Board.hpp"
#include "../../logic_game/HPP_files/Game.hpp"
#include <SDL2/SDL.h>
#include <vector>

class GridSdl : public GameObject {
private:
    Game& game;
    int gridSize;
    int gridPosX;
    int gridPosY;

public:
    GridSdl(Game& game);
    ~GridSdl();

    double posX() override;
    double posY() override;
    double width() override;
    double height() override;
    void drawGrid(SDL_Renderer* renderer);
};

#endif
