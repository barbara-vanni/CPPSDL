#include <iostream>
#include "game/logic_game/HPP_files/Board.hpp"
#include "game/logic_game/HPP_files/Game.hpp"

int main() {
    Board board;
    board.setBoardSize(3);
    board.printBoard();
    board.setTile(4, 4, 'X');
    board.printBoard();
    std::cout << board.getTile(4, 4) << std::endl;
    return 0;
}