#ifndef GRIDSFML_HPP
#define GRIDSFML_HPP

#include "TilesSfml.hpp"
#include "../../GameObject.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"
#include "../../../logic_game/HPP_files/Board.hpp"
#include "../../../logic_game/HPP_files/Game.hpp"
#include <iostream>
#include <vector>

class GridSfml : public GameObject {
    private:
        Game& game;
        int gridSize;
        int gridPosX;
        int gridPosY;


    public:
        GridSfml(Game& game);
        ~GridSfml();

        double posX() override;
        double posY() override;
        double width() override;
        double height() override;
        void drawGrid(sf::RenderWindow* window);
};

#endif