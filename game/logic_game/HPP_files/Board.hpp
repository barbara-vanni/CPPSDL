#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>

class Board {
public:
    Board();
    ~Board();
    void boardInit();
    void addRandomTile();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool okToMove();

private:
    int grid[4][4];
};

#endif // BOARD_HPP
