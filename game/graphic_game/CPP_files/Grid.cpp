#include "../HPP_files/Grid.hpp"

Grid::Grid(int size) : size(size) {
    for (int i = 0; i < size; ++i) {
        std::vector<Tile*> row;
        for (int j = 0; j < size; ++j) {
            row.push_back(new Tile(i * 100, j * 100, 0));  // TILE_SIZE = 100
        }
        grid.push_back(row);
    }
}

void Grid::render(SDL_Renderer* renderer) {
    for (auto& row : grid) {
        for (auto& tile : row) {
            tile->render(renderer);
        }
    }
}

Grid::~Grid() {
    for (auto& row : grid) {
        for (auto& tile : row) {
            delete tile;
        }
    }
}
