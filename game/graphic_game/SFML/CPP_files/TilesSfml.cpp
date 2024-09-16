#include "../HPP_files/TilesSfml.hpp"
#include <iostream>

/*
This class is a tile that can be drawn in a SFML window.
The tile has a rectangle shape.
The tile can be drawn in a window.
The tile has a color that depends on the number in the tile.
*/ 

// Constructor
TilesSfml::TilesSfml(Game& game) : game(game), tileWidth(140), tileHeight(140), currentTile(nullptr), gridPosX(20), gridPosY(200) {
}

// Destructor
TilesSfml::~TilesSfml() {
}

// Getters
double TilesSfml::posX() {
    if (currentTile) {
        double x = gridPosX + currentTile->getPosY() * tileWidth; 
        return x;
    }
    return 0;
}

double TilesSfml::posY() {
    if (currentTile) {
        double y = gridPosY + currentTile->getPosX() * tileHeight;
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

// Setters
void TilesSfml::setTile(Tiles* tile, int gridSize) {
    currentTile = tile;
}

// Draw the tile
void TilesSfml::drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY, int gridSize) {
    setTile(tile, gridSize);
    sf::RectangleShape rectangle(sf::Vector2f(tileWidth, tileHeight));
    rectangle.setPosition(posX(), posY());
    rectangle.setFillColor(getTileColor(tile->getNumberInTile()));
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(sf::Color::White);
    window->draw(rectangle);

     if (tile->getNumberInTile() != 0) {
        sf::Font font;
        if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
            return;
        }

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(tile->getNumberInTile()));
        text.setCharacterSize(40);  
        text.setFillColor(sf::Color::White);  

        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(posX() + tileWidth / 2.0f, posY() + tileHeight / 2.0f);

        window->draw(text);
    }
}

// Get the color of the tile
sf::Color TilesSfml::getTileColor(int value) {
    switch (value) {
        case 2: return sf::Color(45, 45, 45, 255);        
        case 4: return sf::Color(60, 60, 60, 255);        
        case 8: return sf::Color(99, 57, 138, 255);       
        case 16: return sf::Color(148, 81, 255, 255);     
        case 32: return sf::Color(198, 112, 255, 255);    
        case 64: return sf::Color(220, 146, 230, 255);   
        case 128: return sf::Color(184, 136, 71, 255);   
        case 256: return sf::Color(199, 151, 84, 255);   
        case 512: return sf::Color(217, 170, 102, 255);  
        case 1024: return sf::Color(235, 194, 128, 255);  
        case 2048: return sf::Color(255, 224, 153, 255); 
        default: return sf::Color(20, 20, 20, 255);    
    }
}