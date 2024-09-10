#include "../HPP_files/WindowRules.hpp"

WindowRules::WindowRules(int width, int height) : width(width), height(height), title("Rules"), closed(false) {
    init();
}

bool WindowRules::init() {
    Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
    if (!Window) {
        std::cerr << "Error creating window" << std::endl;
        return false;
    }
    return true;
}

void WindowRules::clear() const {
    Window->clear(sf::Color(237, 194, 46));
}

bool WindowRules::isClosed() 
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

sf::RenderWindow* WindowRules::getWindowRules() const {
    return Window.get();
}

void WindowRules::drawImageRules() {
    sf::Texture texture1, texture2, texture3, texture4;
    
    if (!texture1.loadFromFile("assets/images/rule1.png")) {
        std::cerr << "Failed to load rule1.png" << std::endl;
        return;
    }
    
    if (!texture2.loadFromFile("assets/images/rule2.png")) {
        std::cerr << "Failed to load rule2.png" << std::endl;
        return;
    }
    
    if (!texture3.loadFromFile("assets/images/rule3.png")) {
        std::cerr << "Failed to load rule3.png" << std::endl;
        return;
    }

    if (!texture4.loadFromFile("assets/images/arrow.png")) {
        std::cerr << "Failed to load arrow.png" << std::endl;
        return;
    }

    sf::Sprite sprite1(texture1);
    sprite1.setScale(0.35f, 0.35f);
    sprite1.setPosition(30, 100);

    sf::Sprite sprite2(texture2);
    sprite2.setScale(0.35f, 0.35f);
    sprite2.setPosition(30, 350);

    sf::Sprite sprite3(texture3);
    sprite3.setScale(0.35f, 0.35f);
    sprite3.setPosition(30, 600);  

    sf::Sprite sprite4(texture4);
    sprite4.setScale(0.35f, 0.35f);
    sprite4.setPosition(370, 200);

    Window->draw(sprite1);
    Window->draw(sprite2);
    Window->draw(sprite3);
    Window->draw(sprite4);
}

void WindowRules::drawTextRules() {
    sf::Font font;
    if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("RULES");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Black);
    int windowSize = 600;

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(windowSize / 2.0f, 50);


    sf::Text text1;
    text1.setFont(font);
    text1.setString("Use the arrow keys\n\n    to move the tiles.");
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(310, 140);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("       When two tiles with\n\nthe same number touch,\n\n     they merge into one!");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(280, 400);

    sf::Text text3;
    text3.setFont(font);
    text3.setString("  Join the numbers \n\n                   and\n\n get to the 2048 tile!");  
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::Black);
    text3.setPosition(310, 650);

    Window->draw(text);
    Window->draw(text1);
    Window->draw(text2);
    Window->draw(text3);
}
