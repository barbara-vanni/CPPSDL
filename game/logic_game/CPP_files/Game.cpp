//Game.cpp



#include "../HPP_files/Game.hpp"
#include "../HPP_files/Input.hpp"  // Ensure this file exists and is correctly implemented
#include <iostream>

Game::Game() : board(new BoardSdl(4)), score(0), gameOver(false) {
    // Initialization in constructor initializer list
}

Game::~Game() {
    delete board;  // Clean up dynamically allocated memory
}

void Game::start() {
    board->boardInit();
    // Optionally display the initial board state if needed
}

void Game::move() {
    Input input;
    int inputValue = input.getInput();  // Ensure Input class and getInput() method are correctly implemented
    bool moved = false;

    switch (inputValue) {
        case 72:  // Up arrow
            moved = board->moveUp();
            break;
        case 80:  // Down arrow
            moved = board->moveDown();
            break;
        case 75:  // Left arrow
            moved = board->moveLeft();
            break;
        case 77:  // Right arrow
            moved = board->moveRight();
            break;
        case 27:  // ESC key
            gameOver = true;
            break;
    }

    if (moved) {
        board->addRandomTile();
        // Optionally update score here if needed
        // board->displayBoard();  // Optionally display the board state if needed
    }
}

void Game::displayScore() {
    std::cout << "Your score is: " << score << std::endl;
    // Optionally update and display the score if needed
}

bool Game::checkDefeat() {
    // Implement logic to check if the game is over (e.g., no valid moves left)
    return !board->okToMove();  // This is a placeholder; modify based on actual game rules
}

bool Game::checkVictory() {
    // Implement logic to check if the player has won
    // For example, checking if a tile with a certain value exists
    return false;  // Placeholder; replace with actual victory check logic
}
