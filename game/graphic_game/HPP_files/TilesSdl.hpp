#ifndef TILESSdl_HPP
#define TILESSdl_HPP

#include <SDL2/SDL.h>
#include "../GameObject.hpp"
#include "../../logic_game/HPP_files/Tiles.hpp"
#include "../../logic_game/HPP_files/Game.hpp"

class TilesSdl : public GameObject {
private:
    Game& game;
    Tiles* currentTile;
    int tileWidth;
    int tileHeight;
    int gridSize;
    int gridPosX;
    int gridPosY;

    SDL_Color getTileColor(int value);

public:
    TilesSdl(Game& game, int cellSize);
    ~TilesSdl();

    double posX() override;
    double posY() override;
    double width() override;
    double height() override;
    void drawTile(SDL_Renderer* renderer, Tiles* tile, int gridPosX, int gridPosY, int gridSize);
    void setTile(Tiles* tile, int gridSize);
};

#endif
