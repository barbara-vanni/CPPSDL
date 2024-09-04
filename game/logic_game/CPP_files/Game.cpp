// Game.cpp
#include"../HPP_files/Input.hpp"
#include "../HPP_files/Game.hpp"
#include "../../graphic_game/HPP_files/Window.hpp"
#include <SDL2/SDL.h>

Game::Game() : board(new Board(4)), window(new Window(400, 400)), gameOver(false) {}

Game::~Game() {
    delete board;
    delete window;
}

void Game::start() {
    board->boardInit();
}

void Game::move() {
    Input input;
    int inputValue = input.getInput();
    int points = 0;
    bool moved = false;

    if (inputValue == 72) { moved = board->moveUp(); }
    else if (inputValue == 80) { moved = board->moveDown(); }
    else if (inputValue == 75) { moved = board->moveLeft(); }
    else if (inputValue == 77) { moved = board->moveRight(); }
    else if (inputValue == 27) { gameOver = true; }

    if (moved) {
        updateScore(points);
        board->addRandomTile();
        window->clear();
        board->displayBoard(window->getRenderer());
        window->present();
    }
}

bool Game::checkDefeat() {
    if (!board->okToMove()) {
        gameOver = true;
        return true;
    }
    return false;
}

// void Game::displayScore() {
//     // Display score on SDL window or console
// }

// void Game::updateScore(int points) {
//     score.scoreActuel += points;
//     if (score.scoreActuel > score.scoreMax) {
//         score.scoreMax = score.scoreActuel;
//     }
// }

void Game::testDefeatScenario() {
    // Implement test logic here
}
