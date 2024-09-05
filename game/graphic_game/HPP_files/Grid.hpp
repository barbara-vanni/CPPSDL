#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "GameObject.hpp"
#include "Tiles.hpp"

class Grid : public GameObject {
public:
    Grid(int gridSize); // Constructor with size parameter
    ~Grid(); // Destructor

    double setPosX(double x) override;
    double setPosY(double y) override;
    int setCellSize(int size) override; // Renamed from `size` to `setCellSize`

    void renderGrid(SDL_Renderer* renderer, int cellSize); // Changed from displayGrid to renderGrid
    bool moveUp(); // Handle moving tiles up
    bool moveDown(); // Handle moving tiles down
    bool moveLeft(); // Handle moving tiles left
    bool moveRight(); // Handle moving tiles right
    bool okToMove(); // Check if a move is possible
    void addRandomTile(); // Add a new random tile
    void boardInit(); // Initialize the board
    SDL_Color getTileColor(int value); // Get color for tile based on value

    // New method to get the grid
    std::vector<std::vector<Tiles*>>& getGrid(); // Returns a reference to the grid

    SDL_Rect rect; // For positioning and sizing

private:
    int gridSize; // Size of the grid
    std::vector<std::vector<Tiles*>> grid; // 2D grid of tiles
    SDL_Color color;
};
