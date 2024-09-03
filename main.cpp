#include <SDL2/SDL.h>
#include <iostream>
#include "../game/graphic_game/HPP_files/Window.hpp"
#include "../game/logic_game/HPP_files/BoardSdl.hpp"

int main(int argc, char* argv[]) {
    Window window(800, 600);
    if (window.isClosed()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return 1;
    }

    BoardSdl board(4);
    const int cellSize = 150;

    bool quit = false;
    SDL_Event event;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    while (!quit) {
        frameStart = SDL_GetTicks();

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

        window.clear();  // Clear the window
        board.renderBoard(window.getRenderer(), cellSize);  // Render the board and everything on it

        // Frame rate control
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}
