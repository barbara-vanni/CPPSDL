#include "../HPP_files/WindowSfml.hpp"

WindowSfml::WindowSfml(int width, int height)
    : width(width), height(height), title("Night WindowSfml"), closed(false)
{
    init();
}

bool WindowSfml::init()
{
    Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
    rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(200.f, 100.f));
    rectangle->setFillColor(sf::Color::Green);
    rectangle->setPosition(300.f, 250.f);
    return true;
}

void WindowSfml::clear() const
{
    Window->clear(sf::Color::White);
}

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

sf::RenderWindow* WindowSfml::getWindowSfml() const
{
    return Window.get();
}