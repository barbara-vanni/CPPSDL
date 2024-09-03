#include "../HPP_files/Game.hpp"
#include "../HPP_files/Board.hpp"
#include <iostream>

Game::Game() {
    board = new Board(4);
    score = 0;
    gameOver = false;
}

void Game::start() {
    board->boardInit();
    board->displayBoard();
}

void Game::displayScore() {
    std::cout << "Your score is: " << score << std::endl;
}

Game::~Game() {
    delete board;
}


