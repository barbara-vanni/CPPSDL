#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>
#include "Background.hpp"
#include "GridSdl.hpp"

class WindowSdl {
public:
    WindowSdl(int width, int height);
    ~WindowSdl();

    void clear();  // Clears the renderer
    void close();  // Closes the window
    bool isClosed() const;
    SDL_Renderer* getRenderer() const;  // To get the renderer for drawing

private:
    bool init();
    bool closed;

    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::string title;
};

#endif // WINDOW_HPP