#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL2/SDL.h>
#include "../../game/logic_game/HPP_files/BoardSdl.hpp"

class Window {
public:
    Window(int w, int h);
    Window(const std::string &title, int width, int height);
    ~Window();

    void clear() const;
    bool isClosed() const;

    SDL_Renderer* getRenderer() const { return renderer; }  // Function to get the SDL renderer

private:
    bool init();

    std::string title;
    int width;
    int height;
    bool closed;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Board* board;  // Pointer to Board object
};

#endif // WINDOW_HPP
