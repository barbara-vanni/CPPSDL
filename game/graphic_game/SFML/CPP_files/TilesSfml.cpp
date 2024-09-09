#include "../HPP_files/TilesSfml.hpp"
#include <iostream>

TilesSfml::TilesSfml(Game& game) : game(game), tileWidth(140), tileHeight(140), currentTile(nullptr), gridPosX(20), gridPosY(200) {
}

TilesSfml::~TilesSfml() {
}

void TilesSfml::setTile(Tiles* tile, int gridSize) {
    currentTile = tile;
}

double TilesSfml::posX() {
    if (currentTile) {
        double x = gridPosX + currentTile->getPosY() * tileWidth; 
        // std::cout << "posX: " << x << std::endl;  // Debugging
        return x;
    }
    return 0;
}

double TilesSfml::posY() {
    if (currentTile) {
        double y = gridPosY + currentTile->getPosX() * tileHeight;
        // std::cout << "posY: " << y << std::endl;  // Debugging
        return y;
    }
    return 0;
}

double TilesSfml::width() {
    return tileWidth;
}

double TilesSfml::height() {
    return tileHeight;
}

void TilesSfml::drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY, int gridSize) {
    setTile(tile, gridSize);
    sf::RectangleShape rectangle(sf::Vector2f(tileWidth, tileHeight));
    rectangle.setPosition(posX(), posY());
    rectangle.setFillColor(getTileColor(tile->getNumberInTile()));
    window->draw(rectangle);

     if (tile->getNumberInTile() != 0) {
        sf::Font font;
        if (!font.loadFromFile("assets/minecraft_font.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
            return;
        }

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(tile->getNumberInTile()));
        text.setCharacterSize(40);  
        text.setFillColor(sf::Color::Black);  

        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(posX() + tileWidth / 2.0f, posY() + tileHeight / 2.0f);

        window->draw(text);
    }
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