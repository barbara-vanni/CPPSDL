// Window.cpp
#include "../HPP_files/Window.hpp"
#include <iostream>

Window::Window(const std::string& title, int width, int height) 
    : closed(false) {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        closed = true;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        closed = true;
    }
}

Window::~Window() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
}

bool Window::isClosed() const {
    return closed;
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}

void Window::clear() const {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Set to black
    SDL_RenderClear(renderer);
}

void Window::present() const {
    SDL_RenderPresent(renderer);
}
