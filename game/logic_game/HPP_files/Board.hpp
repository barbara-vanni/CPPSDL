#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "Tiles.hpp"
#include <vector>

class Board {
public:
    Board(int size = 4);
    ~Board();
    void boardInit();
    void addRandomTile();
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    bool okToMove();

    void displayBoard();

private:
    // int grid[4][4];
    std::vector<std::vector <Tiles*>> grid;
    int size = 4;

};

#endif // BOARD_HPP
