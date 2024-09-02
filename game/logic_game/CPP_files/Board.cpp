#include <iostream>
#include "../HPP_files/Board.hpp"


Board::Board() {
    board = nullptr;
    boardSize = 0;
}

Board::~Board() {
    for (int i = 0; i < boardSize; i++) {
        delete[] board[i];
    }
    delete[] board;
}


void Board::printBoard(){

}

void Board::setTile(int x, int y, char tile) {
    board[x][y] = tile;
}

char Board::getTile(int x, int y) {
    return board[x][y];
}

void Board::setBoardSize(int size) {
    boardSize = size;
    board = new char*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
    }
}







