#include "../HPP_files/GridSfml.hpp"

GridSfml::GridSfml() : board(4), gridPosX(20), gridPosY(200), gridSize(560) {
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

void GridSfml::displayGrid(sf::RenderWindow* window) {
    sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
    rectangle.setPosition(gridPosX, gridPosY);
    rectangle.setFillColor(sf::Color(255, 255, 255, 255));
    window->draw(rectangle);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board.getGrid()[i][j] != nullptr && board.getGrid()[i][j]->getNumberInTile() != 0) {
                // Debugging: afficher les positions
                // std::cout << "Drawing tile at grid position (" << i << ", " << j << ") with value: " 
                        //   << board.getGrid()[i][j]->getNumberInTile() << std::endl;

                drawTile(window, board.getGrid()[i][j]);
            }
        }
    }
}



void GridSfml::drawTile(sf::RenderWindow* window, Tiles* tile){
    GraphicTiles graphicTile;
    graphicTile.drawTile(window, tile, gridPosX, gridPosY);
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
    bool moved = board.moveUp(newPoint);
    if (moved) {
        board.addRandomTile();  
    }
    return moved;
}

bool GridSfml::moveDown(){
    int newPoint = 0;
    bool moved = board.moveDown(newPoint);
    if (moved) {
        board.addRandomTile();
    }
    return moved;
}

bool GridSfml::moveLeft(){
    int newPoint = 0;
    bool moved = board.moveLeft(newPoint);
    if (moved) {
        board.addRandomTile();
    }
    return moved;
}

bool GridSfml::moveRight(){
    int newPoint = 0;
    bool moved = board.moveRight(newPoint);
    if (moved) {
        board.addRandomTile();
    }
    return moved;
}


