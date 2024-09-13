#include "../HPP_files/GridSfml.hpp"

/*
This class is a grid that can be drawn in a SFML window.
The grid has a rectangle shape.
The grid can be drawn in a window.
*/ 

// Constructor
GridSfml::GridSfml(Game& game) : game(game), gridPosX(20), gridPosY(200), gridSize(560) {
}

// Destructor
GridSfml::~GridSfml() {
}

// Getters
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

// Method to draw the grid
void GridSfml::drawGrid(sf::RenderWindow* window) {
    sf::Color gridColor = sf::Color(140, 140, 140); 
    sf::RectangleShape gridBackground(sf::Vector2f(gridSize, gridSize));
    gridBackground.setPosition(gridPosX, gridPosY);
    gridBackground.setFillColor(gridColor);
    window->draw(gridBackground);

    sf::Color lineColor = sf::Color(100, 100, 100);

    for (int i = 1; i < 4; ++i) {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(gridPosX, gridPosY + i * (gridSize / 4));
        line[0].color = lineColor;
        line[1].position = sf::Vector2f(gridPosX + gridSize, gridPosY + i * (gridSize / 4));
        line[1].color = lineColor;
        window->draw(line);
    }

    for (int j = 1; j < 4; ++j) {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(gridPosX + j * (gridSize / 4), gridPosY);
        line[0].color = lineColor;
        line[1].position = sf::Vector2f(gridPosX + j * (gridSize / 4), gridPosY + gridSize);
        line[1].color = lineColor;
        window->draw(line);
    }

    auto& grid = game.getBoard()->getGrid();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getNumberInTile() != 0) {
                TilesSfml tileSfml(game);
                tileSfml.drawTile(window, grid[i][j], gridPosX, gridPosY, gridSize);
            }
        }
    }
}


