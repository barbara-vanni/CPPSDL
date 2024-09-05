#include "game/logic_game/HPP_files/Game.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Game game("2048", 800, 600);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
