#include "../HPP_files/Game.hpp"
#include <iostream>
#include <ctime>  // For seeding rand()

Game::Game() {
    // Initialize the window and renderer
    window = new Window("2048", 800, 600);
    renderer = window->getRenderer();

    // Initialize the grid
    grid = new Grid(4);  // Initialize the 4x4 grid
    gameOver = false;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Add two initial tiles to the grid
    grid->addRandomTile();
    grid->addRandomTile();

    // Initialize background and tiles
    background = new Background();
    tiles = new Tiles();
}

Game::~Game() {
    // Cleanup dynamically allocated memory
    delete grid;
    delete window;
    delete background;
    delete tiles;
}

void Game::start() {
    SDL_Event event;
    bool running = true;

    while (running) {
        // Event handling loop
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Handle player input and game logic
        move();

        // Check if the game is over (either win or lose)
        if (checkDefeat()) {
            std::cout << "Game Over!" << std::endl;
            running = false;
        }

        // Render the game (grid, tiles, score)
        render();

        // Delay to control frame rate (optional)
        SDL_Delay(100);
    }
}

void Game::move() {
    Input input;
    int inputValue = input.getInput();  // Get player input (arrow keys)
    int points = 0;
    bool moved = false;

    // Handle directional input (move tiles accordingly)
    if (inputValue == 72) {
        moved = grid->moveUp();
    } else if (inputValue == 80) {
        moved = grid->moveDown();
    } else if (inputValue == 75) {
        moved = grid->moveLeft();
    } else if (inputValue == 77) {
        moved = grid->moveRight();
    } else if (inputValue == 27) {  // Escape key to exit
        gameOver = true;
    }

    // If the grid moved, add a new tile and update the score
    if (moved) {
        updateScore(points);
        grid->addRandomTile();
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
    std::cout << "Your score: " << score.scoreActuel << std::endl;
    std::cout << "Best score: " << score.scoreMax << std::endl;
}

void Game::updateScore(int points) {
    score.scoreActuel += points;

    if (score.scoreActuel > score.scoreMax) {
        score.scoreMax = score.scoreActuel;
    }
}

void Game::render() {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);

    // Draw background, grid, and tiles
    background->draw(renderer);
    grid->renderGrid(renderer, 150); // Assume cellSize is 150
    tiles->displayTiles(renderer, grid->getGrid(), *grid);

    // Update the screen
    SDL_RenderPresent(renderer);
}
