#ifndef BOARDSDL_HPP
#define BOARDSDL_HPP

#include <SDL.h>
#include <iostream>
#include <string>

class BoardSdl {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::string title;
    bool closed;

    bool init();

public:
    BoardSdl(int w, int h);
    BoardSdl(const std::string &title, int width, int height);
    ~BoardSdl();

    bool isClosed() const;  // Declaration only
    void clear() const;
};



#endif // BOARDSDL_HPP