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
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int tileX = static_cast<int>(x + j * (w / cols));
            int tileY = static_cast<int>(y + i * (h / rows));
            // Ensure the tile is valid
            int number = (board->getGrid()[i][j]) ? board->getGrid()[i][j]->getNumberInTile() : 0;

            // Create SDL representation of the tile
            tiles.push_back(new TilesSdl(tileX, tileY, w / cols, h / rows, number));
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
