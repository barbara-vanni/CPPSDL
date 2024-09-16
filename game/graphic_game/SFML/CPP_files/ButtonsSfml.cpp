#include "../HPP_files/ButtonsSfml.hpp"
#include <iostream>

/*
This class is a button that can be drawn in a SFML window.
The button has a label and a rectangle shape.
The button can be clicked and the click can be detected.
The button can be drawn in a window.
*/ 

// Constructor
ButtonsSfml::ButtonsSfml(double x, double y, double w, double h, const std::string& label) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(w, h));
    shape.setFillColor(sf::Color(45, 45, 45, 255));
    shape.setOutlineColor(sf::Color(200, 200, 200, 255));
    shape.setOutlineThickness(2);

    if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
    }
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);


    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(x + (w - textBounds.width) / 2, y + (h - textBounds.height) / 2);
}

// Getters
double ButtonsSfml::posX() {
    return shape.getPosition().x;
}

double ButtonsSfml::posY() {
    return shape.getPosition().y;
}

double ButtonsSfml::width() {
    return shape.getSize().x;
}

double ButtonsSfml::height() {
    return shape.getSize().y;
}

// Draw the button
void ButtonsSfml::draw(sf::RenderWindow* window) {
    window->draw(shape);
    window->draw(text);
}

// Check if the button is clicked
bool ButtonsSfml::isClicked(const sf::Vector2i& mousePosition) {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
