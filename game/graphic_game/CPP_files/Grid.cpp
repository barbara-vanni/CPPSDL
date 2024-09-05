#include "../HPP_files/Grid.hpp"
#include "../HPP_files/TilesObject.hpp"
#include <iostream>
#include <ctime>

Grid::Grid(int size) : size(size) {
    srand(static_cast<unsigned>(time(0))); // Seed the RNG
    grid.resize(size);
    for (int i = 0; i < size; ++i) {
        grid[i].resize(size);
        for (int j = 0; j < size; ++j) {
            grid[i][j] = new Tile(i * 70, j * 70, 0);  // TILE_SIZE = 70
        }
    }
    addNewTiles(); // Initialize with 2 tiles
    addNewTiles();
}

void Grid::render(SDL_Renderer* renderer) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j]->render(renderer);
        }
    }
    SDL_RenderPresent(renderer); 
}



void Grid::addNewTiles() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j]->getValue() == 0) {
                emptyTiles.push_back(std::make_pair(i, j));
            }
        }
    }
    if (emptyTiles.empty()) {
        return;
    }
    int randIndex = rand() % emptyTiles.size();
    int x = emptyTiles[randIndex].first;
    int y = emptyTiles[randIndex].second;
    int tileValue = (rand() % 10 < 9) ? 2 : 4;
    grid[x][y]->setValue(tileValue);
}


bool Grid::moveUp(int& newPoint) {
    // move all tiles up
    bool moved = false;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (grid[i][j]->getValue() != 0) {
                int k = i;
                while (k > 0 && (grid[k - 1][j]->getValue() == 0)) {
                    grid[k - 1][j]->setValue(grid[k][j]->getValue());
                    grid[k][j]->setValue(0);
                    moved = true;
                    k--;
                }
                if (k > 0 && grid[k - 1][j]->getValue() == grid[k][j]->getValue()) {
                    grid[k - 1][j]->setValue(grid[k - 1][j]->getValue() * 2);
                    grid[k][j]->setValue(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}


bool Grid::moveDown(int& newPoint) {
    bool moved = false;
    for (int j = 0; j < size; j++) {
        for (int i = size - 1; i >= 0; i--) {
            if (grid[i][j]->getValue() != 0) {
                int k = i;
                while (k < size - 1 && (grid[k + 1][j]->getValue() == 0)) {
                    grid[k + 1][j]->setValue(grid[k][j]->getValue());
                    grid[k][j]->setValue(0);
                    moved = true;
                    k++;
                }
                if (k < size - 1 && grid[k + 1][j]->getValue() == grid[k][j]->getValue()) {
                    grid[k + 1][j]->setValue(grid[k + 1][j]->getValue() * 2);
                    grid[k][j]->setValue(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}


bool Grid::moveLeft(int& newPoint) {
   bool moved = false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j]->getValue() != 0) {
                int k = j;
                while (k > 0 && (grid[i][k - 1]->getValue() == 0)) {
                    grid[i][k - 1]->setValue(grid[i][k]->getValue());
                    grid[i][k]->setValue(0);
                    moved = true;
                    k--;
                }
                if (k > 0 && grid[i][k - 1]->getValue() == grid[i][k]->getValue()) {
                    grid[i][k - 1]->setValue(grid[i][k - 1]->getValue() * 2);
                    grid[i][k]->setValue(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool Grid::moveRight(int& newPoint) {
    // move all tiles right
    bool moved = false;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (grid[i][j]->getValue() != 0) {
                int k = j;
                while (k < size - 1 && (grid[i][k + 1]->getValue() == 0)) {
                    grid[i][k + 1]->setValue(grid[i][k]->getValue());
                    grid[i][k]->setValue(0);
                    moved = true;
                    k++;
                }
                if (k < size - 1 && grid[i][k + 1]->getValue() == grid[i][k]->getValue()) {
                    grid[i][k + 1]->setValue(grid[i][k + 1]->getValue() * 2);
                    grid[i][k]->setValue(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool Grid::okToMove() {
    // check if there are any possible moves left
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j]->getValue() == 0) {
                return true;
            }
            if (i > 0 && grid[i][j]->getValue() == grid[i - 1][j]->getValue()) {
                return true;
            }
            if (i < size - 1 && grid[i][j]->getValue() == grid[i + 1][j]->getValue()) {
                return true;
            }
            if (j > 0 && grid[i][j]->getValue() == grid[i][j - 1]->getValue()) {
                return true;
            }
            if (j < size - 1 && grid[i][j]->getValue() == grid[i][j + 1]->getValue()) {
                return true;
            }
        }
    }
    return false;
}



Grid::~Grid() {
    for (auto& row : grid) {
        for (auto& tile : row) {
            delete tile;
        }
    }
}
