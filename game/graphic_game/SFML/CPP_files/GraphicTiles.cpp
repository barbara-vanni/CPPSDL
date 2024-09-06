#include "../HPP_files/GraphicTiles.hpp"
#include <iostream>

GraphicTiles::GraphicTiles(){
}

GraphicTiles::~GraphicTiles(){
}

double GraphicTiles::posX(){
    return 0;
}

double GraphicTiles::posY(){
    return 0;
}

double GraphicTiles::width(){
    return tileWidth;
}

double GraphicTiles::height(){
    return tileHeight;
}

// void GraphicTiles::drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY){
//     sf::RectangleShape rectangle(sf::Vector2f(tileWidth, tileHeight));
//     rectangle.setPosition(tile->getPosX() * tileWidth + gridPosX, tile->getPosY() * tileHeight + gridPosY);
//     rectangle.setFillColor(getTileColor(tile->getNumberInTile()));
//     window->draw(rectangle);
// }

void GraphicTiles::drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY) {
    sf::RectangleShape rectangle(sf::Vector2f(tileWidth, tileHeight));
    // Utilisation des positions de la tuile pour calculer sa position finale dans la fenêtre SFML
    rectangle.setPosition(tile->getPosX() * tileWidth + gridPosX, tile->getPosY() * tileHeight + gridPosY);
    rectangle.setFillColor(getTileColor(tile->getNumberInTile()));
    rectangle.setOutlineThickness(2);  // Ajouter un contour
    rectangle.setOutlineColor(sf::Color::Black);  // Couleur du contour
    window->draw(rectangle);
}




sf::Color GraphicTiles::getTileColor(int value){
    switch (value)
    {
    case 2:
        return sf::Color(238, 228, 218, 255);
    case 4:
        return sf::Color(237, 224, 200, 255);
    case 8:
        return sf::Color(242, 177, 121, 255);
    case 16:
        return sf::Color(245, 149, 99, 255);
    case 32:
        return sf::Color(246, 124, 95, 255);
    case 64:
        return sf::Color(246, 94, 59, 255); 
    case 128:
        return sf::Color(237, 207, 114, 255);
    case 256:
        return sf::Color(237, 204, 97, 255);
    case 512:
        return sf::Color(237, 200, 80, 255);
    case 1024:
        return sf::Color(237, 197, 63, 255);
    case 2048:
        return sf::Color(237, 194, 46, 255);
    default:
        return sf::Color(204, 192, 179, 255);
    }
    // return sf::Color::White;
}