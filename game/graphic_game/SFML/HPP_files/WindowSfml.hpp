#ifndef WindowSFML_HPP
#define WindowSFML_HPP
#include "../../src/include/SFML/Graphics.hpp"
#include "../../src/include/SFML/Window/Event.hpp"
#include <iostream>
#include <memory>

/*
This class is a window that can be drawn in a SFML window.
The window has a rectangle shape.
The window can be drawn in a window.
*/ 

class WindowSfml {
    private: 
        bool init();
        std::unique_ptr<sf::RenderWindow> Window;
        std::unique_ptr<sf::RectangleShape> rectangle;
        int width;
        int height;
        std::string title;
        bool closed;

    public:
    WindowSfml(int width = 600, int height = 800);
    ~WindowSfml() = default; 
    void clear() const;
    bool isClosed();
    sf::RenderWindow* getWindowSfml() const;
};

#endif 