#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "Tiles.hpp"
#include <vector>

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

#endif // BOARD_HPP
