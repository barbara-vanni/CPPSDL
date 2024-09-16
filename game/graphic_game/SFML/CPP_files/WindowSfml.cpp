#include "../HPP_files/WindowSfml.hpp"
#include <iostream>
#include <memory>

/*
This class is a window that can be drawn in a SFML window.
The window has a rectangle shape.
The window can be drawn in a window.
This class is a window that can be drawn in a SFML window.
*/ 

// Constructor
WindowSfml::WindowSfml(int width, int height)
    : width(width), height(height), title("Night WindowSfml"), closed(false)
{
    init();
}

// Initialize the window
bool WindowSfml::init()
{
    Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
    return true;
}

// Clear the window
void WindowSfml::clear() const
{
    Window->clear(sf::Color (45, 45, 45, 255));
}

// Check if the window is closed
bool WindowSfml::isClosed() 
{
    sf::Event event;
    while (Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            closed = true;
            Window->close();
        }
    }
    return closed;
}

// Draw the window
sf::RenderWindow* WindowSfml::getWindowSfml() const
{
    return Window.get();
}