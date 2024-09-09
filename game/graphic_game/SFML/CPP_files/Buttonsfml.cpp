#include "../HPP_files/Buttonsfml.hpp"
// #include "../../../../assets/minecraft_font.ttf"
#include <iostream>

Buttonsfml::Buttonsfml(double x, double y, double w, double h, const std::string& label) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(w, h));
    shape.setFillColor(sf::Color::Blue);

    // Chargement de la police et configuration du texte
    if (!font.loadFromFile("assets/minecraft_font.ttf")) {
        // std::cout << "Failed to load font" << std::endl;
    }
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Centrer le texte dans le bouton
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(x + (w - textBounds.width) / 2, y + (h - textBounds.height) / 2);
}

// Implémentation des méthodes de GameObject
double Buttonsfml::posX() {
    return shape.getPosition().x;
}

double Buttonsfml::posY() {
    return shape.getPosition().y;
}

double Buttonsfml::width() {
    return shape.getSize().x;
}

double Buttonsfml::height() {
    return shape.getSize().y;
}

// Dessiner le bouton dans la fenêtre SFML
void Buttonsfml::draw(sf::RenderWindow* window) {
    window->draw(shape);
    window->draw(text);
}

// Vérifie si le bouton a été cliqué
bool Buttonsfml::isClicked(const sf::Vector2i& mousePosition) {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
