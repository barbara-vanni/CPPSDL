#include "../../graphic_game/HPP_files/Grid.hpp"
#include "../HPP_files/Game.hpp"
#include <SDL2/SDL_events.h>
#include <iostream>

Game::Game() : gameOver(false) {
    // Initialize Grid with a size (e.g., 4)
    grid = new Grid(4);
    score = Score(); // Initialize Score object
}

void Game::start() {
    grid->render(nullptr);  // Pass a valid SDL_Renderer* if required
}

void Game::move() {
    Input input;
    int inputValue = input.getInput();
    int points = 0;
    bool moved = false;

    if (inputValue == SDLK_UP) {
        moved = grid->moveUp(points);
    } else if (inputValue == SDLK_DOWN) {
        moved = grid->moveDown(points);
    } else if (inputValue == SDLK_LEFT) {
        moved = grid->moveLeft(points);
    } else if (inputValue == SDLK_RIGHT) {
        moved = grid->moveRight(points);
    } else if (inputValue == SDLK_ESCAPE) {
        gameOver = true;
    }

    if (moved) {
        updateScore(points);
        grid->addNewTiles();  // Update with new tiles
        grid->render(nullptr);  // Pass a valid SDL_Renderer* if required
    }
}

bool Game::checkDefeat() {
    if (!grid->okToMove()) {
        gameOver = true;
        return true;
    }
    return false;
}

void Game::displayScore() {
    std::cout << "Your score is: " << score.scoreActuel << std::endl;
    std::cout << "Your best score is: " << score.scoreMax << std::endl;
}

void Game::updateScore(int points) {
    score.scoreActuel += points;

    if (score.scoreActuel > score.scoreMax) {
        score.scoreMax = score.scoreActuel;
    }
}

Game::~Game() {
    delete grid;  // Clean up Grid resources
}
