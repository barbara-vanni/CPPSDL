#pragma once

#include <vector>
#include "TilesObject.hpp"
#include "GameObject.hpp"
#include "../../logic_game/HPP_files/Board.hpp"

class Grid : public GameObject, public Board {
private:
    int size;
    std::vector<std::vector<Tile*>> grid;
public:
    Grid(int size = 4);
    void render(SDL_Renderer* renderer) override;
    void addNewTiles();
    bool moveUp(int& newPoint);
    bool moveDown(int& newPoint);
    bool moveLeft(int& newPoint);
    bool moveRight(int& newPoint);
    bool okToMove();
    ~Grid();
};
