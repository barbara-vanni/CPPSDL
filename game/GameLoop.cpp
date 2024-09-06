#include "GameLoop.hpp"
#include <iostream>

GameLoop::GameLoop(const std::string &title, int width, int height) {
    window = new Window(title, width, height);  // Initialize the window
    game = new Game();  // Initialize the game logic
    board = new Board();  // Initialize the game board
    running = true;
}

GameLoop::~GameLoop() {
    delete window;
    delete game;
    delete board;
}

void GameLoop::run() {
    SDL_Event event;

    while (running) {
        handleEvents();
        updateGame();
        render();
    }
}

void GameLoop::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }

        if (e.type == SDL_KEYDOWN && !game->getGameOver()) {
            int points = 0;
            bool moved = false;

            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    game->move();
                    break;
                case SDLK_DOWN:
                    game->move();
                    break;
                case SDLK_LEFT:
                    game->move();
                    break;
                case SDLK_RIGHT:
                    game->move();
                    break;
                case SDLK_ESCAPE:
                    running = false;
                    break;
            }

            if (moved) {
                game->updateScore(points);
                board->addRandomTile();
            }

            if (game->checkDefeat()) {
                std::cout << "Game Over!" << std::endl;
            }
        }
    }
}

void GameLoop::updateGame() {
    // Additional game logic can be added here (like animations or delays)
}

void GameLoop::render() {
    window->run();  // Render the window, grid, and background
    game->displayGrid(window->run());  // Pass SDL renderer to game for rendering grid/tiles
}
