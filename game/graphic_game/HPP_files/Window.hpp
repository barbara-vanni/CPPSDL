// Window.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    bool isClosed() const;
    SDL_Renderer* getRenderer() const;
    void clear() const;
    void present() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool closed;
};

#endif // WINDOW_HPP
