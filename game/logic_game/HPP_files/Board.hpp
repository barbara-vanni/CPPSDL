#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "../HPP_files/Tiles.hpp"
#include <vector>

/*
This class is the board of the game, it will contain the grid of the game
This class will also contain the logic of the game
*/ 

class Board
{
public:
    Board(int size = 4);
    ~Board();
    void boardInit();
    void addRandomTile();
    bool moveUp(int& newPoint);
    bool moveDown(int& newPoint);
    bool moveLeft(int& newPoint);
    bool moveRight(int& newPoint);
    bool okToMove();

    void displayBoard();

    std::vector<std::vector<Tiles *>>& getGrid();

private:

    std::vector<std::vector<Tiles *>> grid;
    int size = 4;
};

#endif
