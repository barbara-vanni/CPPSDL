#include "../HPP_files/BoardSdl.hpp"

Board::Board(int size, SDL_Renderer* renderer) : size(size), renderer(renderer) {
    boardInit();
}

Board::~Board() {
    // Cleanup Tiles objects in the grid
    for (auto& row : grid) {
        for (auto& tile : row) {
            delete tile;
        }
    }
}

void Board::boardInit() {
    grid.resize(size, std::vector<Tiles*>(size, nullptr));

    // Initialize the board with a couple of random tiles
    addRandomTile();
    addRandomTile();
}

void Board::addRandomTile() {
    // Add logic to place a random tile on the board
}

bool Board::moveUp() { 
    // Implement movement logic
    return true;
}

bool Board::moveDown() { 
    // Implement movement logic
    return true;
}

bool Board::moveLeft() { 
    // Implement movement logic
    return true; 
}

bool Board::moveRight() { 
    // Implement movement logic
    return true; 
}

bool Board::okToMove() {
    // Implement logic to check if a move is possible
    return true;
}

void Board::displayBoard() {
    // For terminal display (if needed)
}

void Board::render() {
    int tileSize = 100;  // Size of each tile on the board
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                renderTile(i * tileSize, j * tileSize, grid[i][j]->getValue());
            }
        }
    }
}

void Board::renderTile(int x, int y, int value) {
    SDL_Rect tileRect = { x, y, 100, 100 };  // Define the rectangle size
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);  // Set color for the tile
    SDL_RenderFillRect(renderer, &tileRect);  // Draw the tile

    // You can render the value of the tile as text here using SDL_ttf, if needed
}
