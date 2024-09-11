#include "../HPP_files/ScoreSfml.hpp"


ScoreSfml::ScoreSfml(Game& game, double x, double y, const std::string& label)
    : game(game) {
    if (!font.loadFromFile("assets/font/minecraft_font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(34);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
}

void ScoreSfml::draw(sf::RenderWindow* window) {
    window->draw(text);
}

void ScoreSfml::updateActualScore(int score) {

    int scoreActuel = game.getScoreActuel();

    text.setString(std::to_string(scoreActuel) );
}

void ScoreSfml::updateBestScore(int score) {

    int bestScore = game.getBestScore();

    text.setString( std::to_string(bestScore));
}


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


