#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "game/graphic_game/HPP_files/Window.hpp"
#include "game/logic_game/HPP_files/Tiles.hpp" // Changed from Tiles.hpp to Tile.hpp
#include "game/logic_game/HPP_files/Board.hpp"
#include "game/logic_game/HPP_files/Game.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CELL_SIZE = 100;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    Window window("2048 Game", WINDOW_WIDTH, WINDOW_HEIGHT);
    if (window.isClosed()) {
        TTF_Quit();
        SDL_Quit();
        return 1; // Exit if window initialization failed
    }

    Game game;
    game.start();

    bool running = true;
    SDL_Event event;

    while (running) {
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:    board.moveUp(); break;
                case SDLK_DOWN:  Board.moveDown(); break;
                case SDLK_LEFT:  Board.moveLeft(); break;
                case SDLK_RIGHT: Board.moveRight(); break;
            }
        }
    }

    // Update game state
    game.move();

    // Clear the window
    window.clear();

    // Draw the game board
    game.displayBoard(window.getRenderer());

    // Draw the score
    game.displayScore(); // Ensure this method updates the renderer

    // Present the renderer
    SDL_RenderPresent(window.getRenderer());

    // Check if the game is over
    if (game.getGameOver()) {
        running = false;
    }

    SDL_Delay(100); // Adjust the delay for desired game speed
}

    TTF_Quit();
    SDL_Quit();
    return 0;
}
