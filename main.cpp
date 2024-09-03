#include <iostream>
#include "game/logic_game/HPP_files/Board.hpp"
#include "game/logic_game/HPP_files/Tiles.hpp"

int main() {
    // creation of the board
    Board board(4);
    // seed for random number generation base on the actual hour 
    srand(static_cast<unsigned int>(time(0)));

    board.boardInit();
    board.displayBoard();
;


    // Tiles* tile1 = new Tiles(0, 0, 2);
    // Tiles* tile2 = new Tiles(0, 1, 2);

    // std::cout << "Before merging :" << std::endl;
    // std::cout << "Tile 1 number: " << tile1->getNumberInTile() << std::endl;
    // std::cout << "Tile 2 number: " << tile2->getNumberInTile() << std::endl;

    // int newNumber = tile1->mergeTilesNumbers(tile2);

    // std::cout << "After merging :" << std::endl;
    // std::cout << "Tile 1 number: " << newNumber << std::endl;
    // std::cout << "Tile 2 number: " << tile2->getNumberInTile() << std::endl;


    // Tiles* tile3 = new Tiles(1, 0, 4);
    // Tiles* tile4 = new Tiles(1, 1, 2);

    // std::cout << "\nBefore merging :" << std::endl;
    // std::cout << "Tile 3 number: " << tile3->getNumberInTile() << std::endl;
    // std::cout << "Tile 4 number: " << tile4->getNumberInTile() << std::endl;

    // newNumber = tile3->mergeTilesNumbers(tile4);

    // std::cout << "After the merging try :" << std::endl;
    // std::cout << "Tile 3 number: " << newNumber << std::endl;
    // std::cout << "Tile 4 number: " << tile4->getNumberInTile() << std::endl;


    // delete tile1;
    // delete tile2;
    // delete tile3;
    // delete tile4;
    return 0;
}
