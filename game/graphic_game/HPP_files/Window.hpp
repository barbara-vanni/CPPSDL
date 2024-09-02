#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h>
#include <iostream>
#include <string>

class Window {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::string title;
    bool closed;

    bool init();

public:
    Window(int w, int h);
    Window(const std::string &title, int width, int height);
    ~Window();

    bool isClosed() const;  // Declaration only
    void clear() const;
};

#endif // WINDOW_HPP
