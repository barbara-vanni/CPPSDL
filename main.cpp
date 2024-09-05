#include <SDL2/SDL.h>
#include <iostream>  // For std::cerr
#include "game/logic_game/HPP_files/Game.hpp"
#include "game/graphic_game/HPP_files/Window.hpp"
#include "game/graphic_game/HPP_files/Background.hpp"
#include "game/graphic_game/HPP_files/Grid.hpp"
#include "game/graphic_game/HPP_files/Button.hpp"
#include "game/graphic_game/HPP_files/Score.hpp"

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    Window window;
    if (!window.init()) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    Background bg;
    Grid grid(4);  // 4x4 grid
    Button restartButton(650, 500, 100, 50, "Restart");
    // Score scoreDisplay(650, 50);

    // Initialize Game object
    Game game;

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                // Handle input for game
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                    case SDLK_DOWN:
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                        game.move(); // Update game state based on input
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }
        }

        // Game logic
        if (!game.checkDefeat()) {
            // Game logic updates and rendering can be handled here
            game.move();
            game.checkDefeat();
            // Example: Update the score based on game logic
            game.updateScore(0);  // Pass actual points if needed
        }

        // Render
        bg.render(window.renderer);                // Render background
        grid.render(window.renderer);              // Render grid and tiles
        restartButton.render(window.renderer);    // Render restart button
        // scoreDisplay.render(window.renderer);     // Render score

        // Render game-specific elements if needed
        // game.render(window.renderer);           // Implement a render method in Game if needed

        SDL_RenderPresent(window.renderer);       // Update the screen

        // Check game state and quit if game is over
        if (game.checkDefeat()) {
            quit = true;
        }
    }

    // Clean up
    window.cleanUp();
    SDL_Quit();
    return 0;
}
