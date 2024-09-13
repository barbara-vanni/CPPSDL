#include "../HPP_files/WindowMenu.hpp"
#include "../HPP_files/ButtonsSfml.hpp"

/*
This class is a window that can be drawn in a SFML window.
The window has a title and buttons.
The window can be drawn in a window.
*/ 

// Constructor
WindowMenu::WindowMenu(int width, int height)
    : width(width), height(height), title("2048 WindowMenu"), closed(false)
{
    init();
}

// Initialize window
bool WindowMenu::init()
{
    Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
    return true;
}

// Clear window
void WindowMenu::clear() const
{
    Window->clear(sf::Color(237, 230, 218));
}

// Check if window is closed
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

// Draw buttons
sf::RenderWindow* WindowMenu::getWindowMenu() const
{
    return Window.get();
}

// Draw buttons
WindowMenu::MenuOption WindowMenu::drawButtons() {
    sf::Font font;
    if (!font.loadFromFile("assets/font/minecraft_font.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("MENU\n2048");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color(119, 110, 101));
    int windowSize = 600;

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(windowSize / 2.0f, 140);

    ButtonsSfml gameButton(windowSize / 2.0f - 125, 310, 250, 80, "PLAY");
    ButtonsSfml nightModeButton(windowSize / 2.0f - 125, 450, 250, 80, "NIGHT MODE");
    ButtonsSfml howToPlayButton(windowSize / 2.0f - 125, 590, 250, 80, "HOW TO PLAY");

    Window->draw(text);
    gameButton.draw(Window.get());
    nightModeButton.draw(Window.get());
    howToPlayButton.draw(Window.get());

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);

        if (gameButton.isClicked(mousePos)) {
            return MenuOption::PLAY;
        }
        else if (nightModeButton.isClicked(mousePos)) {
            return MenuOption::NIGHT_MODE;
        }
        else if (howToPlayButton.isClicked(mousePos)) {
            return MenuOption::HOW_TO_PLAY;
        }
    }
    return MenuOption::NONE; 
}
