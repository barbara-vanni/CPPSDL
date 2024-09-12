#ifndef WINDOWRULES_HPP
#define WINDOWRULES_HPP

#include "../../src/include/SFML/Graphics.hpp"
#include "../../src/include/SFML/Window/Event.hpp"
#include <iostream>
#include <memory>

class WindowRules {
    private: 
        bool init();
        std::unique_ptr<sf::RenderWindow> Window;
        std::unique_ptr<sf::RectangleShape> rectangle;
        int width;
        int height;
        std::string title;
        bool closed;

    public:
    WindowRules(int width = 600, int height = 800);
    ~WindowRules() = default; 
    void clear() const;
    bool isClosed();
    sf::RenderWindow* getWindowRules() const;

    void drawImageRules();
    void drawTextRules();
};
#endif