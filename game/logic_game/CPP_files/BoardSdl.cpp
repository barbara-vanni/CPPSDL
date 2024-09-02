#include "BoardSdl.hpp"
#include <cstdlib>
#include <ctime>

Board::Board(int size, SDL_Renderer* renderer) : size(size), renderer(renderer) {
    std::cout << "Board constructor called" << std::endl;
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed the random number generator
    boardInit();
}

void Board::boardInit() {
    grid.resize(size, std::vector<Tiles*>(size, nullptr));
    addRandomTile();
    addRandomTile();
}

void Board::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == nullptr || grid[i][j]->getNumberInTile() == 0) {
                emptyTiles.push_back(std::make_pair(i, j));
            }
        }
    }

    if (emptyTiles.empty()) return;

    int randIndex = rand() % emptyTiles.size();
    int x = emptyTiles[randIndex].first;
    int y = emptyTiles[randIndex].second;

    int tileValue = (rand() % 10 < 9) ? 2 : 4;

    Tiles* newTile = new Tiles(x, y, tileValue);
    grid[x][y] = newTile;
}

void Board::displayBoard() {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);  // Background color

    int tileSize = 100;  // Size of each tile

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                renderTile(i * tileSize, j * tileSize, grid[i][j]->getNumberInTile());
            } else {
                renderTile(i * tileSize, j * tileSize, 0);  // Empty tile
            }
        }
    }

    SDL_RenderPresent(renderer);  // Present the updated renderer
}

void Board::renderTile(int x, int y, int value) {
    SDL_Rect tileRect = { x, y, 100, 100 };

    if (value == 0) {
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);  // Empty tile color
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Tile color (e.g., yellow)
    }

    SDL_RenderFillRect(renderer, &tileRect);

    // If you want to display the value as text, you'll need to integrate SDL_ttf here
    // You would render the text on top of the tileRect
}

Board::~Board() {
    std::cout << "Board destructor called" << std::endl;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }
}
