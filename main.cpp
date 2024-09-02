#include "game/graphic_game/HPP_files/Window.hpp"

int main() {
    Window window(600, 600);

    // Main loop
    while (!window.isClosed()) {
        window.clear();
        SDL_Delay(16);  // Adjust delay for frame rate control
    }

    return 0;
}
