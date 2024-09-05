#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "../HPP_files/Tiles.hpp"
#include "../HPP_files/Grid.hpp"

Grid::Grid(int size) : gridSize(size) {
    if (size <= 0) {
        throw std::invalid_argument("Grid size must be positive.");
    }

    rect.x = 0;
    rect.y = 0;
    rect.w = 150; // CELL SIZE
    rect.h = 150; // CELL SIZE
    color = {255, 255, 255, 255};

    boardInit();
}

Grid::~Grid() {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            delete grid[i][j];
            grid[i][j] = nullptr; // Prevent double deletion
        }
    }
}


double Grid::setPosX(double x) {
    rect.x = x;
    return rect.x;
}

double Grid::setPosY(double y) {
    rect.y = y;
    return rect.y;
}


int Grid::setCellSize(int size) {
    rect.w = size;
    rect.h = size;
    return rect.w;
}













void Grid::boardInit() {
    grid.resize(gridSize);
    for (int i = 0; i < gridSize; i++) {
        grid[i].resize(gridSize);
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = new Tiles();
        }
    }
    addRandomTile();
    addRandomTile();
}

void Grid::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
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

SDL_Color Grid::getTileColor(int value) {
    switch (value) {
        case 2: return {238, 228, 218, 255};
        case 4: return {237, 224, 200, 255};
        case 8: return {242, 177, 121, 255};
        case 16: return {245, 149, 99, 255};
        case 32: return {246, 124, 95, 255};
        case 64: return {246, 94, 59, 255};
        case 128: return {237, 207, 114, 255};
        case 256: return {237, 204, 97, 255};
        case 512: return {237, 200, 80, 255};
        case 1024: return {237, 197, 63, 255};
        case 2048: return {237, 194, 46, 255};
        default: return {204, 192, 179, 255}; // Default color
    }
}

bool Grid::moveUp() {
    bool moved = false;
    for (int j = 0; j < gridSize; j++) {
        for (int i = 0; i < gridSize; i++) {
            if (grid[i][j]->getValue() != 0) {
                int k = i;
                while (k > 0 && grid[k - 1][j]->getValue() == 0) {
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

bool Grid::moveDown() {
    bool moved = false;
    for (int j = 0; j < gridSize; j++) {
        for (int i = gridSize - 1; i >= 0; i--) {
            if (grid[i][j]->getValue() != 0) {
                int k = i;
                while (k < gridSize - 1 && grid[k + 1][j]->getValue() == 0) {
                    grid[k + 1][j]->setValue(grid[k][j]->getValue());
                    grid[k][j]->setValue(0);
                    moved = true;
                    k++;
                }
                if (k < gridSize - 1 && grid[k + 1][j]->getValue() == grid[k][j]->getValue()) {
                    grid[k + 1][j]->setValue(grid[k + 1][j]->getValue() * 2);
                    grid[k][j]->setValue(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool Grid::moveLeft() {
    bool moved = false;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j]->getValue() != 0) {
                int k = j;
                while (k > 0 && grid[i][k - 1]->getValue() == 0) {
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

bool Grid::moveRight() {
    bool moved = false;
    for (int i = 0; i < gridSize; i++) {
        for (int j = gridSize - 1; j >= 0; j--) {
            if (grid[i][j]->getValue() != 0) {
                int k = j;
                while (k < gridSize - 1 && grid[i][k + 1]->getValue() == 0) {
                    grid[i][k + 1]->setValue(grid[i][k]->getValue());
                    grid[i][k]->setValue(0);
                    moved = true;
                    k++;
                }
                if (k < gridSize - 1 && grid[i][k + 1]->getValue() == grid[i][k]->getValue()) {
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
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j]->getValue() == 0) {
                return true;
            }
            if (i > 0 && grid[i][j]->getValue() == grid[i - 1][j]->getValue()) {
                return true;
            }
            if (i < gridSize - 1 && grid[i][j]->getValue() == grid[i + 1][j]->getValue()) {
                return true;
            }
            if (j > 0 && grid[i][j]->getValue() == grid[i][j - 1]->getValue()) {
                return true;
            }
            if (j < gridSize - 1 && grid[i][j]->getValue() == grid[i][j + 1]->getValue()) {
                return true;
            }
        }
    }
    return false;
}

std::vector<std::vector<Tiles*>>& Grid::getGrid() {
    return grid;
}

void Grid::renderGrid(SDL_Renderer* renderer, int cellSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            SDL_Rect cellRect = { j * cellSize, i * cellSize, cellSize, cellSize };
            int tileValue = grid[i][j]->getValue();
            SDL_Color tileColor = getTileColor(tileValue);
            SDL_SetRenderDrawColor(renderer, tileColor.r, tileColor.g, tileColor.b, tileColor.a);
            SDL_RenderFillRect(renderer, &cellRect);
        }
    }

    

    // Draw grid lines
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int i = 0; i <= gridSize; i++) {
        SDL_RenderDrawLine(renderer, rect.x, rect.y + i * rect.h, rect.x + gridSize * rect.w, rect.y + i * rect.h);
        SDL_RenderDrawLine(renderer, rect.x + i * rect.w, rect.y, rect.x + i * rect.w, rect.y + gridSize * rect.h);
    }

    SDL_RenderPresent(renderer); 
}
