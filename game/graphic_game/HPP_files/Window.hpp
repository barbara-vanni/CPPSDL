#pragma once

#include <SDL2/SDL.h>

class Window {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;

    Window();
    bool init();
    void cleanUp();
};


