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
    // Set the color for the 1px black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Create the border rectangle for the grid
    SDL_Rect gridBorder = { gridPosX - 2, gridPosY - 2, gridSize + 4, gridSize + 4 };
    SDL_RenderDrawRect(renderer, &gridBorder);

    // Set the background color for the grid
    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);

    // Create the background rectangle for the grid
    SDL_Rect gridBackground = { gridPosX, gridPosY, gridSize, gridSize };
    SDL_RenderFillRect(renderer, &gridBackground);

    auto& grid = game.getBoard()->getGrid();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getNumberInTile() != 0) {
                TilesSdl tileSdl(game);
                tileSdl.drawTile(renderer, grid[i][j], gridPosX, gridPosY, gridSize);
            }
        }
    }
}

