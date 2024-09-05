#include "../game/graphic_game/HPP_files/Window.hpp"
#include "../game/graphic_game/HPP_files/Background.hpp"
#include "../game/graphic_game/HPP_files/Grid.hpp"
#include "../game/graphic_game/HPP_files/Tiles.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <ctime>  // For seeding rand()

int main(int argc, char* argv[]) {
    // Initialize Window with title "2048" and dimensions 800x600
    Window window("2048", 800, 600);

    // Initialize background, grid, and tiles
    Background background;
    Grid grid;
    Tiles tiles;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Initialize 4x4 grid data (filled with 0s initially)
    int** gridData = new int*[4];
    for (int i = 0; i < 4; i++) {
        gridData[i] = new int[4]{0};  // Initialize each row to all 0s
    }
    // Get the renderer from the window object
    SDL_Renderer* renderer = window.getRenderer();

    // Add the first random tile to start the game
    grid.addNewTile(renderer, gridData);
    grid.addNewTile(renderer, gridData);


    // Main loop control variable
    bool running = true;

    // SDL Event for handling input
    SDL_Event event;

    // Main game loop
    while (running) {
        // Event handling loop
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;  // Exit loop if the window is closed
            }
            // Example: You can add key press logic to move tiles
            // and call grid.addNewTile(gridData) after a move.
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
        SDL_RenderClear(renderer);

        // Drawing the background using the renderer
        background.draw(renderer);

        // Drawing the grid using the renderer
        grid.displayGrid(renderer);

        // Drawing the tiles using the renderer and grid object
        tiles.displayTiles(renderer, gridData, grid);


        // Present the renderer (updates the screen with the latest render)
        SDL_RenderPresent(renderer);

        // Add some delay for testing, to slow down tile generation
        SDL_Delay(1000);  // Delay for 1 second
    }

    // Cleanup
    for (int i = 0; i < 4; i++) {
        delete[] gridData[i];
    }
    delete[] gridData;

    // Cleanup before exit (Window destructor will handle it automatically)
    SDL_Quit();

    return 0;
}
