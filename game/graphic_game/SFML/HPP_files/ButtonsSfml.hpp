#ifndef BUTTONSSFML_HPP
#define BUTTONSSFML_HPP

#include "../../GameObject.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"

/*
This class is a button that can be drawn in a SFML window.
The button has a label and a rectangle shape.
The button can be clicked and the click can be detected.
*/

class ButtonsSfml : public GameObject {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    
public:
    ButtonsSfml(double x, double y, double w, double h, const std::string& label);

    double posX() override;
    double posY() override;
    double width() override;
    double height() override;

    void draw(sf::RenderWindow* window);
    bool isClicked(const sf::Vector2i& mousePosition);
};

#endif
