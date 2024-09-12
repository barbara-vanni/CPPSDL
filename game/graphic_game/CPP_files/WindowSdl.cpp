#include "../HPP_files/WindowSdl.hpp"
#include <iostream>


/*This class is responsible of displaying the window in SDL */
WindowSdl::WindowSdl(int width, int height)
    : width(width), height(height), title("Grid Game"), closed(false), window(nullptr), renderer(nullptr) {
    if (!init()) {
        closed = true;
    }
}

WindowSdl::~WindowSdl() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool WindowSdl::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

void WindowSdl::clear() {
    SDL_SetRenderDrawColor(renderer, 237, 230, 218, 255);  
    SDL_RenderClear(renderer);
}

void WindowSdl::close() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    TTF_Quit();
    SDL_Quit();
    closed = true;
}


bool WindowSdl::isClosed() const {
    return closed;
}

SDL_Renderer* WindowSdl::getRenderer() const {
    return renderer;
}
