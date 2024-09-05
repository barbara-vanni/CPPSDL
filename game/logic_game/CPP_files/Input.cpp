#include "../HPP_files/Input.hpp"
#include <stdio.h>
#include <ncurses.h>
#include <iostream>
#include <SDL2/SDL_events.h>

Input::Input() {
    std::cout << "Constructor called" << std::endl;
}

Input::~Input() {
    std::cout << "Destructor called" << std::endl;
}

int Input::getInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 27;  // ESC key to quit
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    std::cout << "Up" << std::endl;
                    return SDLK_UP;
                case SDLK_DOWN:
                    std::cout << "Down" << std::endl;
                    return SDLK_DOWN;
                case SDLK_LEFT:
                    std::cout << "Left" << std::endl;
                    return SDLK_LEFT;
                case SDLK_RIGHT:
                    std::cout << "Right" << std::endl;
                    return SDLK_RIGHT;
                case SDLK_ESCAPE:
                    return 27;  // ESC key to quit
                default:
                    std::cout << "Press arrow keys to move the tiles or ESC to quit" << std::endl;
                    break;
            }
        }
    }
    return -1;  // No valid input
}