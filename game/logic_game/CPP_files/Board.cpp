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


void Board::printBoard() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize - 1; j++) {
            std::cout << board[i][j] << '*';
        }
        std::cout << std::endl;
    }
}

void Board::setTile(int x, int y, char tile) {
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize) {
        board[x][y] = tile;
    } else {
        std::cerr << "Error: Attempt to access out-of-bounds index (" << x << ", " << y << ")" << std::endl;
    }
}

char Board::getTile(int x, int y) {
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize) {
        return board[x][y];
    } else {
        std::cerr << "Error: Attempt to access out-of-bounds index (" << x << ", " << y << ")" << std::endl;
        return '\0'; // Return a null character if out of bounds
    }
}

void Board::setBoardSize(int size) {
    // Clean up any existing board memory before resizing
    if (board != nullptr) {
        for (int i = 0; i < boardSize; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

    boardSize = size;
    board = new char*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
        // Initialize the board with empty spaces or any default value
        for (int j = 0; j < size; j++) {
            board[i][j] = ' ';
        }
    }
}







