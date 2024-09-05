#include "../game/graphic_game/HPP_files/Window.hpp"
#include "../game/graphic_game/HPP_files/Background.hpp"
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize Window with title "2048" and dimensions 800x600
    Window window("2048", 800, 600);

    // Initialize background
    Background background;

    // Get the renderer from the window object
    SDL_Renderer* renderer = window.getRenderer();

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
        }

        // Drawing the background using the renderer
        background.draw(renderer);

        // Present the renderer (updates the screen with the latest render)
        SDL_RenderPresent(renderer);
    }

    // Cleanup before exit (Window destructor will handle it automatically)
    SDL_Quit();

    return 0;
}
