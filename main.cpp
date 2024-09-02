#include "game/graphic_game/HPP_files/Window.hpp"

int main() {
    Window window(800, 600);

    while (!window.isClosed()) {
        window.clear();
        SDL_Delay(16);
    }

    return 0;
}
