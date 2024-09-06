#include "../HPP_files/GridSfml.hpp"

GridSfml::GridSfml(Game& game) : game(game), gridPosX(20), gridPosY(200), gridSize(560) {
}

GridSfml::~GridSfml() {
}

double GridSfml::posX() {
    return gridPosX;
}

double GridSfml::posY() {
    return gridPosY;
}

double GridSfml::width() {
    return gridSize;
}

double GridSfml::height() {
    return gridSize;
}

void GridSfml::drawGrid(sf::RenderWindow* window) {
    sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
    auto& grid = game.getBoard()->getGrid();
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (grid[i][j] != nullptr && grid[i][j]->getNumberInTile() != 0) {
                TilesSfml tilessfml(game);
                tilessfml.drawTile(window, grid[i][j], gridPosX, gridPosY);
            //     rectangle.setFillColor(sf::Color(140, 140, 140, 255));
            //     window->draw(rectangle);
            }
        }
    }
}
