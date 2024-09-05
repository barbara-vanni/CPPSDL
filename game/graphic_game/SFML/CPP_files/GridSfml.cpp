#include "../HPP_files/GridSfml.hpp"

GridSfml::GridSfml() : board(4) {
    board.boardInit();
}

GridSfml::~GridSfml(){
}

double GridSfml::posX() {
    return gridPosX;
}

double GridSfml::posY(){
    return gridPosY;
}

double GridSfml::width(){
    return gridSize;
}

double GridSfml::height(){
    return gridSize;
}

void GridSfml::displayGrid(sf::RenderWindow* window){
    sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
    rectangle.setPosition(gridPosX, gridPosY);

    rectangle.setFillColor(sf::Color(255, 255, 255, 255));
    window->draw(rectangle);
}
void GridSfml::drawTile(sf::RenderWindow* window, Tiles* tile){
    GraphicTiles graphicTile;
    graphicTile.drawTile(window, tile);
}




void GridSfml::checkDefeat(Board* board){
    if (!board->okToMove()) {
        std::cout << "Game Over" << std::endl;
    }
}

void GridSfml::okToMove(){
    if (board.okToMove()) {
        board.addRandomTile();
    }
}

bool GridSfml::moveUp(){
    int newPoint = 0;
    return board.moveUp(newPoint);
}

bool GridSfml::moveDown(){
    int newPoint = 0;
    return board.moveDown(newPoint);
}

bool GridSfml::moveLeft(){
    int newPoint = 0;
    return board.moveLeft(newPoint);
}

bool GridSfml::moveRight(){
    int newPoint = 0;
    return board.moveRight(newPoint);
}

