#ifndef ScoreSFML_HPP
#define ScoreSFML_HPP


#include "../../src/include/SFML/Graphics.hpp"
#include "../../../logic_game/HPP_files/Game.hpp"
#include <iostream>

/*
This class is a score that can be drawn in a SFML window.
The score has a label and a text.
The score can be drawn in a window.
*/

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
