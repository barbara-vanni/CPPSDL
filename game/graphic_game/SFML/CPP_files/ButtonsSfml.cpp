#include "../HPP_files/ButtonsSfml.hpp"
#include <iostream>

ButtonsSfml::ButtonsSfml(double x, double y, double w, double h, const std::string& label) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(w, h));
    shape.setFillColor(sf::Color(45, 45, 45, 255));
    shape.setOutlineColor(sf::Color(200, 200, 200, 255));
    shape.setOutlineThickness(2);

    // Chargement de la police et configuration du texte
    if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
        // std::cout << "Failed to load font" << std::endl;
    }
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);


    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(x + (w - textBounds.width) / 2, y + (h - textBounds.height) / 2);
}

// Implémentation des méthodes de GameObject
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

// Dessiner le bouton dans la fenêtre SFML
void ButtonsSfml::draw(sf::RenderWindow* window) {
    window->draw(shape);
    window->draw(text);
}

// Vérifie si le bouton a été cliqué
bool ButtonsSfml::isClicked(const sf::Vector2i& mousePosition) {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
