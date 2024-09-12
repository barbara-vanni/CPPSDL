#include "../HPP_files/GridSdl.hpp"

GridSdl::GridSdl(Game& game) : game(game), gridPosX(20), gridPosY(200), gridSize(560) {}

GridSdl::~GridSdl() {}

double GridSdl::posX() {
    return gridPosX;
}

double GridSdl::posY() {
    return gridPosY;
}

double GridSdl::width() {
    return gridSize;
}

double GridSdl::height() {
    return gridSize;
}

void GridSdl::drawGrid(SDL_Renderer* renderer) {
    // Set the color for the 2px black border around the entire grid
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Create and draw the black border rectangle for the grid
    SDL_Rect gridBorder = { gridPosX - 1, gridPosY - 1, gridSize + 2, gridSize + 2 };
    SDL_RenderDrawRect(renderer, &gridBorder);

    // Set the background color for the grid
    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);

    // Create and fill the background rectangle for the grid
    SDL_Rect gridBackground = { gridPosX, gridPosY, gridSize, gridSize };
    SDL_RenderFillRect(renderer, &gridBackground);

    // Get the grid data from the game
    auto& grid = game.getBoard()->getGrid();

    // Calculate the cell size dynamically based on gridSize
    int cellSize = gridSize / 4;

    // Initialize a single instance of TilesSdl to avoid creating it in the loop
    TilesSdl tileSdl(game, cellSize); // Pass the cellSize to the constructor

    // Now draw each cell's border and contents
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            // Draw a 1px black border around each cell
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect cellBorder = { gridPosX + i * cellSize, gridPosY + j * cellSize, cellSize, cellSize };
            SDL_RenderDrawRect(renderer, &cellBorder);

            // Draw the tiles if present
            if (grid[i][j] != nullptr && grid[i][j]->getNumberInTile() != 0) {
                tileSdl.drawTile(renderer, grid[i][j], gridPosX + i * cellSize, gridPosY + j * cellSize, cellSize);
            }
        }
    }
}



