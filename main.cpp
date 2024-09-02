#include <iostream>
#include "game/logic_game/HPP_files/Board.hpp"

int main() {
    // creation of the board
    Board board;
    // seed for random number generation base on the actual hour 
    srand(static_cast<unsigned int>(time(0)));

    board.boardInit();
    board.displayBoard();


    return 0;
}