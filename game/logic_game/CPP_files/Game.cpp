#include "../HPP_files/Game.hpp"
#include "../HPP_files/Board.hpp"
// #include "../HPP_files/Score.hpp"
#include "../src/include/SFML/Window.hpp"

#include <iostream>

Game::Game() {
    board = new Board(4);
    Score score;
    gameOver = false;
}

void Game::start() {
    board->boardInit();
    board->displayBoard();
}

void Game::move() {
    Input input;
    int inputValue = input.getInput();
    int points = 0;
    bool moved = false;

    if (inputValue == 72) {
        moved = board->moveUp(points);
    } else if (inputValue == 80) {
        moved = board->moveDown(points);
    } else if (inputValue == 75) {
        moved = board->moveLeft(points);
    } else if (inputValue == 77) {
        moved = board->moveRight(points);
    } else if (inputValue == 27) {
        gameOver = true;
    }        

    if (moved) {
        updateScore(points);
        board->addRandomTile();
        board->displayBoard();
    }
}

void Game::moveSfml(int inputValue) {
    int points = 0;
    bool moved = false;

    if (inputValue == sf::Keyboard::Up) {
        moved = board->moveUp(points);
    } else if (inputValue == sf::Keyboard::Down) {
        moved = board->moveDown(points);
    } else if (inputValue == sf::Keyboard::Left) {
        moved = board->moveLeft(points);
    } else if (inputValue == sf::Keyboard::Right) {
        moved = board->moveRight(points);
    } else if (inputValue == sf::Keyboard::Escape) {
        gameOver = true;
    }        

    if (moved) {
        updateScore(points);
        board->addRandomTile();
        board->displayBoard();
    }
}



bool Game::checkDefeat() {
    if (board->okToMove() == false) {
        gameOver = true;
        return true;
    }
    else {
        return false;
    }
}

void Game::displayScore() {
    std::cout << "Your score is: " << score.scoreActuel << std::endl;
    std::cout << "Your best score is: " << score.scoreMax << std::endl;
}

void Game::updateScore(int points)
{
    
    score.scoreActuel += points;

    if (score.scoreActuel > score.scoreMax)
    {
        score.scoreMax = score.scoreActuel;
    }

    
}

Game::~Game() {
    delete board;
}


/* TEST */

void Game::testDefeatScenario() {

    auto& grid = board->getGrid();

    board->boardInit();


    grid[0][0] = new Tiles(0, 0, 2);
    grid[0][1] = new Tiles(0, 1, 4);
    grid[0][2] = new Tiles(0, 2, 2);
    grid[0][3] = new Tiles(0, 3, 4);

    grid[1][0] = new Tiles(1, 0, 4);
    grid[1][1] = new Tiles(1, 1, 2);
    grid[1][2] = new Tiles(1, 2, 4);
    grid[1][3] = new Tiles(1, 3, 2);

    grid[2][0] = new Tiles(2, 0, 2);
    grid[2][1] = new Tiles(2, 1, 4);
    grid[2][2] = new Tiles(2, 2, 2);
    grid[2][3] = new Tiles(2, 3, 4);

    grid[3][0] = new Tiles(3, 0, 4);
    grid[3][1] = new Tiles(3, 1, 2);
    grid[3][2] = new Tiles(3, 2, 4);
    grid[3][3] = new Tiles(3, 3, 2);

    board->displayBoard();

    // check if the game is over when no moves are possible
    if (checkDefeat()) {
        std::cout << "Test passed: Game Over detected." << std::endl;
    } else {
        std::cout << "Test failed: Game Over not detected." << std::endl;
    }
}