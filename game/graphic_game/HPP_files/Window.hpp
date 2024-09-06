#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>
#include "Background.hpp"
#include "GridSdl.hpp"

class Window {
public:
    Window(int width, int height);
    Window(const std::string &title, int width, int height);
    ~Window();

    void run();  // This will handle the main loop
    bool closed;

private:
    void render();
    bool init();
    void handleEvents();

    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::string title;

    Background* background;
    Grid* grid;
};

#endif // WINDOW_HPP
