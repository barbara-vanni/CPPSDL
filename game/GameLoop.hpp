#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include <SDL2/SDL.h>
#include <string>
#include "graphic_game/HPP_files/Window.hpp"
#include "logic_game/HPP_files/Game.hpp"

class GameLoop {
public:
    GameLoop(const std::string &title, int width, int height);
    ~GameLoop();
    void run();  // Main game loop

private:
    void handleEvents();
    void updateGame();
    void render();

    Window* window;  // Responsible for graphics and window management
    Game* game; 
    Board* board;     // Responsible for game logic (2048 game)

    bool running;    // Game loop state
};

#endif // GAME_LOOP_HPP
