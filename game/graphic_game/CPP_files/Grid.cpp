#include "../HPP_files/Grid.hpp"
#include "../HPP_files/TilesObject.hpp"
#include <iostream>


Grid::Grid(int size) : size(size) {
    for (int i = 0; i < size; ++i) {
        std::vector<Tile*> row;
        for (int j = 0; j < size; ++j) {
            row.push_back(new Tile(i * 70, j * 70, 0));  // TILE_SIZE = 100
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

void Grid::addNewTiles() {
    // add new tiles to the grid 
    for (int i = 0; i < size; ++i) {
         for (int j = 0; j < size; ++j) {
            if (grid[i][j]->getValue() == 0) {
                delete grid[i][j];
                grid[i][j] = new Tile(i * 70, j * 70, 0);  // TILE_SIZE = 100
            }
        }
    }
}


bool Grid::moveUp(int& newPoint) {
    // move all tiles up
    bool moved = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j]->getValue() != 0) {
                int k = j;
                while (k > 0 && grid[i][k - 1]->getValue() == 0) {
                    --k;
                }
                if (k != j) {
                    if (grid[i][k]->getValue() == grid[i][j]->getValue()) {
                        grid[i][k]->setValue(grid[i][k]->getValue() * 2);
                        newPoint += grid[i][k]->getValue();
                        grid[i][j]->setValue(0);
                        moved = true;
                    } else {
                        grid[i][k]->setValue(grid[i][j]->getValue());
                        grid[i][j]->setValue(0);
                    }
                }
            }
        }
    }
    return moved;
}

bool Grid::moveDown(int& newPoint) {
    // move all tiles down
    bool moved = false;
    for (int i = 0; i < size; ++i) {
        for (int j = size - 1; j >= 0; --j) {
            if (grid[i][j]->getValue() != 0) {
                int k = j;
                while (k < size - 1 && grid[i][k + 1]->getValue() == 0) {
                    ++k;
                }
                if (k != j) {
                    if (grid[i][k]->getValue() == grid[i][j]->getValue()) {
                        grid[i][k]->setValue(grid[i][k]->getValue() * 2);
                        newPoint += grid[i][k]->getValue();
                        grid[i][j]->setValue(0);
                        moved = true;
                    } else {
                        grid[i][k]->setValue(grid[i][j]->getValue());
                        grid[i][j]->setValue(0);
                    }
                }
            }
        }
    }
    return moved;
}


bool Grid::moveLeft(int& newPoint) {
    // move all tiles left
    bool moved = false;
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            if (grid[i][j]->getValue() != 0) {
                int k = i;
                while (k > 0 && grid[k - 1][j]->getValue() == 0) {
                    --k;
                }
                if (k != i) {
                    if (grid[k][j]->getValue() == grid[i][j]->getValue()) {
                        grid[k][j]->setValue(grid[k][j]->getValue() * 2);
                        newPoint += grid[k][j]->getValue();
                        grid[i][j]->setValue(0);
                        moved = true;
                    } else {
                        grid[k][j]->setValue(grid[i][j]->getValue());
                        grid[i][j]->setValue(0);
                    }
                }
            }
        }
    }
    return moved;
}

bool Grid::moveRight(int& newPoint) {
    // move all tiles right
    bool moved = false;
    for (int j = 0; j < size; ++j) {
        for (int i = size - 1; i >= 0; --i) {
            if (grid[i][j]->getValue() != 0) {
                int k = i;
                while (k < size - 1 && grid[k + 1][j]->getValue() == 0) {
                    ++k;
                }
                if (k != i) {
                    if (grid[k][j]->getValue() == grid[i][j]->getValue()) {
                        grid[k][j]->setValue(grid[k][j]->getValue() * 2);
                        newPoint += grid[k][j]->getValue();
                        grid[i][j]->setValue(0);
                        moved = true;
                    } else {
                        grid[k][j]->setValue(grid[i][j]->getValue());
                        grid[i][j]->setValue(0);
                    }
                }
            }
        }
    }
    return moved;
}

bool Grid::okToMove() {
    // check if there are any possible moves left
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
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
