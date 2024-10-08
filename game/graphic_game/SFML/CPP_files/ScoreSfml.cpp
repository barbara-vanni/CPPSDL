#include "../HPP_files/ScoreSfml.hpp"

/*
This class is a score that can be drawn in a SFML window.
The score has a label and a text.
The score can be drawn in a window.
The score can be updated.
*/ 

// Constructor
ScoreSfml::ScoreSfml(Game& game, double x, double y, const std::string& label)
    : game(game) {
    if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    labelText.setFont(font);
    labelText.setString(label);
    labelText.setCharacterSize(20); 
    labelText.setFillColor(sf::Color::White);
    labelText.setPosition(x, y);

    text.setFont(font);
    text.setString(""); 
    text.setCharacterSize(34); 
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y + 40);
}

// Draw the score
void ScoreSfml::draw(sf::RenderWindow* window) {
    window->draw(labelText);
    window->draw(text);
}

// Update the actual score
void ScoreSfml::updateActualScore(int score) {

    int actualScore = game.getActualScore();

    text.setString(std::to_string(actualScore) );
}

// Update the best score
void ScoreSfml::updateBestScore(int score) {

    int bestScore = game.getBestScore();

    text.setString( std::to_string(bestScore));
}

// Draw the game over message
void ScoreSfml::drawGameOver(sf::RenderWindow* window) {
    sf::Text gameOverText;
    sf::Font font;
    if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(90);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(20, 400); 

    sf::FloatRect textBounds = gameOverText.getGlobalBounds();

    sf::RectangleShape backgroundRect;
    backgroundRect.setSize(sf::Vector2f(textBounds.width + 50, textBounds.height + 50)); 
    backgroundRect.setPosition(textBounds.left - 10, textBounds.top - 10); 
    backgroundRect.setFillColor(sf::Color(45, 45, 45, 255));

    window->draw(backgroundRect);
    window->draw(gameOverText); 
}


