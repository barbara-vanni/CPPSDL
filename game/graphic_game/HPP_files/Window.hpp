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

    void clear();  // Clears the renderer
    bool isClosed() const;
    SDL_Renderer* getRenderer() const;  // To get the renderer for drawing

private:
    void render();
    bool init();
    bool closed;

    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::string title;
};

#endif // WINDOW_HPP
