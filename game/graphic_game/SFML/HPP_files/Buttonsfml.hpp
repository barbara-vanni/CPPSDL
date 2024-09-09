#ifndef BUTTONSFML_HPP
#define BUTTONSFML_HPP

#include "../../GameObject.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"


class Buttonsfml : public GameObject {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    
public:
    Buttonsfml(double x, double y, double w, double h, const std::string& label);


    double posX() override;
    double posY() override;
    double width() override;
    double height() override;

    void draw(sf::RenderWindow* window);
    bool isClicked(const sf::Vector2i& mousePosition);
};

#endif
