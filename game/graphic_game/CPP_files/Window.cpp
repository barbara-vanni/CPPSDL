#include "../HPP_files/Window.hpp"

Window::Window(int w, int h) : width(w), height(h), title("2048"), closed(false) {
    if (!init()) {
        closed = true;
    }
}

Window::Window(const std::string &title, int width, int height) : title(title), width(width), height(height), closed(false) {
    if (!init()) {
        closed = true;
    }
}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();  // Clean up SDL before returning
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);  // Clean up the window
        SDL_Quit();  // Clean up SDL
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255);  

    return true;
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::clear() const {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Window::isClosed() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true;
        }
    }
    return closed;
}
