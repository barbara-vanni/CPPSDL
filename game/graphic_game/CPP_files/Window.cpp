#include "../HPP_files/Window.hpp"
#include <iostream>

Window::Window(int w, int h)
    : width(w), height(h), title("Grid Game"), closed(false), background(nullptr), grid(nullptr) {
    if (!init()) {
        closed = true;
    }
}

Window::Window(const std::string &title, int width, int height)
    : title(title), width(width), height(height), closed(false), background(nullptr), grid(nullptr) {
    if (!init()) {
        closed = true;
    }
}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() < 0) {
        std::cerr << "TTF initialization failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return false;
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
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return false;
    }

    // Initialize background and grid
    background = new Background(0, 0, width, height);
    grid = new Grid(20, 200, 560, 560, 4, 4);

    return true;
}

Window::~Window() {
    delete grid;
    delete background;
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    TTF_Quit();
    SDL_Quit();
}

void Window::run() {
    SDL_Event e;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        render();
    }
}

void Window::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    background->draw(renderer);
    grid->draw(renderer);

    SDL_RenderPresent(renderer);
}
