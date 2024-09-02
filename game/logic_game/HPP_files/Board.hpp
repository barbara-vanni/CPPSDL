#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>

class Board {
public:
    Board();
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
    int grid[4][4];
};

#endif // BOARD_HPP
