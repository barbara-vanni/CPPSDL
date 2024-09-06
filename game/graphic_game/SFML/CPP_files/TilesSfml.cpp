#include "../HPP_files/TilesSfml.hpp"
#include <iostream>

TilesSfml::TilesSfml(Game& game) : game(game), tileWidth(140), tileHeight(140) {
}

TilesSfml::~TilesSfml() {
}

double TilesSfml::posX() {
    return 0;
}

double TilesSfml::posY() {
    return 0;
}

double TilesSfml::width() {
    return tileWidth;
}

double TilesSfml::height() {
    return tileHeight;
}

void TilesSfml::drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY) {
    sf::RectangleShape rectangle(sf::Vector2f(tileWidth, tileHeight));
    rectangle.setPosition(tile->getPosX() * tileWidth + gridPosX, tile->getPosY() * tileHeight + gridPosY);
    rectangle.setFillColor(getTileColor(tile->getNumberInTile()));
    window->draw(rectangle);
}

sf::Color TilesSfml::getTileColor(int value) {
    switch (value) {
        case 2: return sf::Color(238, 228, 218, 255);
        case 4: return sf::Color(237, 224, 200, 255);
        case 8: return sf::Color(242, 177, 121, 255);
        case 16: return sf::Color(245, 149, 99, 255);
        case 32: return sf::Color(246, 124, 95, 255);
        case 64: return sf::Color(246, 94, 59, 255);
        case 128: return sf::Color(237, 207, 114, 255);
        case 256: return sf::Color(237, 204, 97, 255);
        case 512: return sf::Color(237, 200, 80, 255);
        case 1024: return sf::Color(237, 197, 63, 255);
        case 2048: return sf::Color(237, 194, 46, 255);
        default: return sf::Color(204, 192, 179, 255);
    }
}