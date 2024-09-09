#include "../HPP_files/WindowMenu.hpp"
#include "../HPP_files/ButtonSfml.hpp"

WindowMenu::WindowMenu(int width, int height)
    : width(width), height(height), title("2048 WindowMenu"), closed(false)
{
    init();
}

bool WindowMenu::init()
{
    Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
    return true;
}

void WindowMenu::clear() const
{
    Window->clear(sf::Color(237, 230, 218));
}

bool WindowMenu::isClosed() 
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

sf::RenderWindow* WindowMenu::getWindowMenu() const
{
    return Window.get();
}

void WindowMenu::drawButtons()
{
    sf::Font font;
    if (!font.loadFromFile("assets/minecraft_font.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
    }

    // Title
    sf::Text text;
    text.setFont(font);
    text.setString("MENU\n2048");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color(119, 110, 101));
    int windowSize = 600;

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(windowSize / 2.0f, 140);

    // Game button
    ButtonSfml gameButton(windowSize / 2.0f - 125, 310, 250, 80, "PLAY");
    gameButton.isClicked(sf::Mouse::getPosition(*Window));    

    // Night mode button
    ButtonSfml nightModeButton(windowSize / 2.0f - 125, 450, 250, 80, "NIGHT MODE");
    nightModeButton.isClicked(sf::Mouse::getPosition(*Window));

    // How to play button
    ButtonSfml howToPlayButton(windowSize / 2.0f - 125, 590, 250, 80, "HOW TO PLAY");
    howToPlayButton.isClicked(sf::Mouse::getPosition(*Window));

    Window->draw(text);
    gameButton.draw(Window.get());
    nightModeButton.draw(Window.get());
    howToPlayButton.draw(Window.get());
}