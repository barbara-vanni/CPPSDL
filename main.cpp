#include <SDL2/SDL.h>
#include "game/graphic_game/HPP_files/Window.hpp"
#include "game/graphic_game/HPP_files/Background.hpp"
#include "game/graphic_game/HPP_files/Grid.hpp"
#include "game/graphic_game/HPP_files/Button.hpp"
#include "game/graphic_game/HPP_files/Score.hpp"

int main(int argc, char* args[]) {
    Window window;
    if (!window.init()) {
        return -1;
    }

    Background bg;
    Grid grid(4);  // 4x4 grid
    Button restartButton(650, 500, 100, 50, "Restart");
    Score scoreDisplay(650, 50);

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Render
        bg.render(window.renderer);          // Render background
        grid.render(window.renderer);        // Render grid and tiles
        restartButton.render(window.renderer);  // Render restart button
        scoreDisplay.render(window.renderer);   // Render score

        SDL_RenderPresent(window.renderer);  // Update the screen
    }

    window.cleanUp();
    return 0;
}
