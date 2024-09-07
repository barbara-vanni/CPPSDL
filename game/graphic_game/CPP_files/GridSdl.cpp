#include "../HPP_files/GridSdl.hpp"
#include <iostream>
#include <SDL2/SDL.h>

Grid::Grid(double x, double y, double w, double h, int rows, int cols) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->rows = rows;
    this->cols = cols;
    color = {187, 173, 160, 255};

    // Initialize the board
    board = new Board(rows);
    board->boardInit();

    // Check if the board was initialized correctly
    if (!board) {
        std::cerr << "Board initialization failed" << std::endl;
        return;
    }

    // Create the individual TilesSdl objects
    auto& grid = board->getGrid();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double tileX = x + j * (w / cols);
            double tileY = y + i * (h / rows);

            // Ensure grid[i][j] is not null before accessing
            if (grid[i][j] != nullptr) {
                int number = grid[i][j]->getNumberInTile();  // Assuming Tiles has a getNumber method
                tiles.push_back(new TilesSdl(tileX, tileY, w / cols, h / rows, number));
            }
        }
    }

    // Add initial random tile
    board->addRandomTile();

    // Add the new tile to SDL representation
    auto& newGrid = board->getGrid();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (newGrid[i][j] != nullptr && std::find_if(tiles.begin(), tiles.end(), 
                        [&](const TilesSdl* tile) { return tile->get() == std::make_pair(tileX, tileY); }) == tiles.end()) {
                double sdlTileX = x + j * (w / cols);
                double sdlTileY = y + i * (h / rows);
                tiles.push_back(new TilesSdl(sdlTileX, sdlTileY, w / cols, h / rows, newGrid[i][j]->getNumber()));
            }
        }
    }
}

double Grid::posX() {
    return x;
}

double Grid::posY() {
    return y;
}

double Grid::width() {
    return w;
}

double Grid::height() {
    return h;
}

void Grid::draw(SDL_Renderer* renderer) {
    // Draw the grid's background
    SDL_Rect gridRect = {static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h)};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &gridRect);

    // Draw each tile (TilesSdl) in the grid
    for (auto& tileSdl : tiles) {
        tileSdl->draw(renderer);  // Assuming TilesSdl has its own draw method
    }
}

Grid::~Grid() {
    // Clean up the SDL tiles
    for (auto& tile : tiles) {
        delete tile;
    }

    // Clean up the board
    delete board;
}
