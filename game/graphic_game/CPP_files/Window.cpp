#include "../HPP_files/Window.hpp"
#include <iostream>

Window::Window(int width, int height)
    : width(width), height(height), title("Grid Game"), closed(false), window(nullptr), renderer(nullptr) {
    if (!init()) {
        closed = true;
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
    SDL_RenderClear(renderer);
}

bool Window::isClosed() const {
    return closed;
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}
