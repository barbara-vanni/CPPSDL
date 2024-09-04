// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

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
    void displayBoard(SDL_Renderer* renderer) const;

private:
    std::vector<std::vector<Tile*>> grid;
    int size;
};

#endif // BOARD_HPP
