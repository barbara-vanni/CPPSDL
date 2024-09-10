#include "../HPP_files/ScoreSfml.hpp"


ScoreSfml::ScoreSfml(Game& game, double x, double y, const std::string& label)
    : game(game) {
    if (!font.loadFromFile("assets/minecraft_font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
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


