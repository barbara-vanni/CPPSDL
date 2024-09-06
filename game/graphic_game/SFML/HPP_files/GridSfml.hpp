#ifndef GRIDSFML_HPP
#define GRIDSFML_HPP

#include "GraphicTiles.hpp"
#include "../../GameObject.hpp"
#include "../../../../src/include/SFML/Graphics/Color.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"
#include "../../../logic_game/HPP_files/Board.hpp"
#include <iostream>
#include <vector>

class GridSfml : public GameObject {

    private:
        Board board;
        int gridSize = 560;
        int gridPosX = 20;
        int gridPosY = 200;
        // int cellSize = 140;
        Tiles* grid[4][4];

    public:
        GridSfml();
        ~GridSfml();

        double posX() override;
        double posY() override;
        double width() override;
        double height() override;

        void displayGrid(sf::RenderWindow* window);
        void drawTile(sf::RenderWindow* window, Tiles* tile);

        void checkDefeat(Board* board);
        void okToMove();   

        bool moveUp();
        bool moveDown();
        bool moveLeft();
        bool moveRight();     
};

#endif