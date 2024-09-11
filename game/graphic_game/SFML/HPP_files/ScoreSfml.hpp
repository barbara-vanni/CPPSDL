#ifndef ScoreSFML_HPP
#define ScoreSFML_HPP


#include "../../src/include/SFML/Graphics.hpp"
#include "../../../logic_game/HPP_files/Game.hpp"
#include <iostream>

class ScoreSfml
{
private:
    Game& game;
    sf::Text text;
    sf::Text labelText;
    sf::Font font;
public:
    ScoreSfml(Game& game, double x, double y, const std::string& label);
    void draw(sf::RenderWindow* window);
    void updateActualScore(int score);    
    void updateBestScore(int score);

    void drawGameOver(sf::RenderWindow* window);
};

#endif
