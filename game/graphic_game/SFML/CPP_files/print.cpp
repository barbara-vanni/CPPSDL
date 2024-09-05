#include "../HPP_files/print.hpp"
#include <iostream>

int printSfml()
{
    std::cout << "Programme démarré" << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(300.f, 250.f);

    std::cout << "Fenêtre et rectangle créés" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }

    std::cout << "Programme terminé" << std::endl;

    return 0;
}