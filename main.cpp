#include <SDL2/SDL.h>
#include <iostream>
#include "../game/graphic_game/HPP_files/Window.hpp"
#include "../game/logic_game/HPP_files/BoardSdl.hpp"

int main(int argc, char* argv[]) {
    // Initialize SDL
    Window window(800, 800);
    if (window.isClosed()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return 1;
    }

    BoardSdl board(4);
    const int cellSize = 200; // Adjust this size based on window size and board size

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                bool moved = false;
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        moved = board.moveUp();
                        break;
                    case SDLK_DOWN:
                        moved = board.moveDown();
                        break;
                    case SDLK_LEFT:
                        moved = board.moveLeft();
                        break;
                    case SDLK_RIGHT:
                        moved = board.moveRight();
                        break;
                }
                if (moved) {
                    board.addRandomTile();
                }
            }
        }

        if (!board.okToMove()) {
            std::cout << "Game Over!" << std::endl;
            quit = true;
        }

        window.clear();
        board.renderBoard(window.getRenderer(), cellSize);
        SDL_Delay(100); // Adjust this delay as needed
    }   

    return 0;
}
