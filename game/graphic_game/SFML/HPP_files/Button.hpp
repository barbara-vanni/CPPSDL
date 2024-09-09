#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../../src/include/SFML/Graphics.hpp"
#include "../../GameObject.hpp"
#include <iostream>
#include <memory>


class Button : public GameObject {
    private: 
        bool init();
        std::unique_ptr<sf::RenderWindow> Window;
        std::unique_ptr<sf::RectangleShape> rectangle;
        std::string title;
        bool closed;

    public:
    Button(int width = 60, int height = 80);
    ~Button() = default; 
    double width() override;
    double height() override;
    void clear() const;
    void isClicked();
    sf::RenderWindow* getWindowSfml() const;
};

#endif