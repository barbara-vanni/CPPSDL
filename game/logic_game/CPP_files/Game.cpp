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

void Game::move() {
    Input input;
    int inputValue = input.getInput();
    bool moved = false;

    if (inputValue == 72) {
        moved = board->moveUp();
    } else if (inputValue == 27) {
        gameOver = true;
    // } else if (inputValue == 2) {
    //     moved = board->moveDown();
    // } else if (inputValue == 3) {
    //     moved = board->moveLeft();
    } else if (inputValue == 77) {
        moved = board->moveRight();
    }

    if (moved) {
        board->addRandomTile();
        board->displayBoard();
    }
}

void Game::displayScore() {
    std::cout << "Your score is: " << score << std::endl;
}

Game::~Game() {
    delete board;
}


