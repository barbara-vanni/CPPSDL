#include "game/logic_game/HPP_files/GameLoop.hpp"

int main() {
    GameLoop gameLoop("2048 Game", 600, 800);
    gameLoop.run();
    return 0;
}

