#include "../HPP_files/WindowMenu.hpp"

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
    Window->clear(sf::Color::Blue);
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
    text.setString("2048");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    int windowSize = 600;

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(windowSize / 2.0f, 80);

    // Game button
    sf::RectangleShape gameButton(sf::Vector2f(250, 80));
    gameButton.setFillColor(sf::Color::Green);
    gameButton.setPosition(windowSize / 2.0f - 125, 200);

    // Text on game button
    sf::Text gameText;
    gameText.setFont(font);
    gameText.setString("PLAY");
    gameText.setCharacterSize(50);
    gameText.setFillColor(sf::Color::White);
    sf::FloatRect gameTextRect = gameText.getLocalBounds();
    gameText.setOrigin(gameTextRect.left + gameTextRect.width / 2.0f, gameTextRect.top + gameTextRect.height / 2.0f);
    gameText.setPosition(windowSize / 2.0f, 240);

    // Night mode button
    sf::RectangleShape nightModeButton(sf::Vector2f(250, 80));
    nightModeButton.setFillColor(sf::Color::Black);
    nightModeButton.setPosition(windowSize / 2.0f - 125, 400);

    // Text on night mode button
    sf::Text nightModeText;
    nightModeText.setFont(font);
    nightModeText.setString("NIGHT MODE");
    nightModeText.setCharacterSize(30);
    nightModeText.setFillColor(sf::Color::White);
    sf::FloatRect nightModeTextRect = nightModeText.getLocalBounds();
    nightModeText.setOrigin(nightModeTextRect.left + nightModeTextRect.width / 2.0f, nightModeTextRect.top + nightModeTextRect.height / 2.0f);
    nightModeText.setPosition(windowSize / 2.0f, 440);
    
    Window->draw(text);
    Window->draw(gameButton);
    Window->draw(nightModeButton);
    Window->draw(gameText);
    Window->draw(nightModeText);
}