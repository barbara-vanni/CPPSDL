#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(int width, int height);
    Window(const std::string &title, int width, int height);
    ~Window();

    void clear() const;
    bool isClosed() const;
    SDL_Renderer* getRenderer() const; // Add this method

private:
    bool init();
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::string title;
    bool closed;
};

#endif // WINDOW_HPP
