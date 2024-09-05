#pragma once

#include <vector>
#include "TilesObject.hpp"
#include "GameObject.hpp"

class Grid : public GameObject {
private:
    int size;
    std::vector<std::vector<Tile*>> grid;
public:
    Grid(int size = 4);
    void render(SDL_Renderer* renderer) override;
    ~Grid();
};
