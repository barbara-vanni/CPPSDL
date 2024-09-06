#include "game/graphic_game/HPP_files/Window.hpp"

int main(int argc, char* argv[]) {
    Window window(600, 800);
    window.run();  // The window handles everything (loop, rendering, etc.)
    return 0;
}
