#include "../HPP_files/WindowSfml.hpp"

WindowSfml::WindowSfml(int width, int height)
    : width(width), height(height), title("Night Window"), closed(false)
{
    init();
}

WindowSfml::WindowSfml(const std::string &title, int width, int height)
    : width(width), height(height), title(title), closed(false)
{
    init();
}

bool WindowSfml::init()
{
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
    rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(200.f, 100.f));
    rectangle->setFillColor(sf::Color::Green);
    rectangle->setPosition(300.f, 250.f);
    return true;
}

void WindowSfml::clear() const
{
    window->clear(sf::Color::Black);
}

bool WindowSfml::isClosed() 
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            closed = true;
            window->close();
        }
    }
    return closed;
}

sf::RenderWindow* WindowSfml::getWindow() const
{
    return window.get();
}