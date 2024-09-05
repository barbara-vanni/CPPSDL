#include "../HPP_files/Game.hpp"
#include <iostream>
#include <ctime>  // For seeding rand()

Game::Game(const std::string& title, int width, int height) 
    : window(title, width, height), renderer(window.getRenderer()) {
    if (window.isClosed()) {
        std::cerr << "Window initialization failed!" << std::endl;
        throw std::runtime_error("Window initialization failed");
    }

    // Initialize grid data
    initializeGrid();

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Add the first two random tiles to start the game
    grid.addNewTile(renderer, gridData);
    grid.addNewTile(renderer, gridData);
}

Game::~Game() {
    cleanup();
}

void Game::initializeGrid() {
    gridData = new int*[4];
    for (int i = 0; i < 4; i++) {
        gridData[i] = new int[4]{0};  // Initialize each row to all 0s
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            window.isClosed();  // Mark the window as closed
        }
        // Example: Handle key presses here to move tiles
        // You would also want to add logic to handle movement and tile merging
    }
}

void Game::update() {
    // Add game logic updates here, such as moving tiles
    // This function will be called in the game loop to process the game state
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);

    background.draw(renderer);
    grid.displayGrid(renderer);
    tiles.displayTiles(renderer, gridData, grid);

    SDL_RenderPresent(renderer);
}

void Game::cleanup() {
    for (int i = 0; i < 4; i++) {
        delete[] gridData[i];
    }
    delete[] gridData;

    // Cleanup is handled by Window destructor, no need to call SDL_Quit() explicitly
}

void Game::run() {
    bool running = true;
    while (running) {
        handleEvents();
        update();
        render();
        SDL_Delay(1000);  // Delay for 1 second
        running = !window.isClosed();  // Continue running while the window is open
    }
}
