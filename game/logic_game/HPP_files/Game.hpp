#ifndef GAME_HPP
#define GAME_HPP

#include "../../graphic_game/HPP_files/Background.hpp"  
#include "../../graphic_game/HPP_files/Grid.hpp"
#include "../../graphic_game/HPP_files/Tiles.hpp"
#include "../../graphic_game/HPP_files/Window.hpp"
#include <SDL2/SDL.h>

class Game {
public:
    Game(const std::string& title, int width, int height);
    ~Game();

    void run();

private:
    Window window;
    Background background;
    Grid grid;
    Tiles tiles;
    SDL_Renderer* renderer;
    int** gridData;

    void initializeGrid();
    void handleEvents();
    void update();
    void render();
    void cleanup();
};

#endif // GAME_HPP
