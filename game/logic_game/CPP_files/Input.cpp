#include "../HPP_files/Input.hpp"
#include <stdio.h>
#include "SDL2/SDL.h"
#include "conio.h"
// #include <ncurses.h>
#include <iostream>

Input::Input() {
    std::cout << "Constructor called" << std::endl;
}

Input::~Input() {
    std::cout << "Destructor called" << std::endl;
}

int Input::getInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            return event.key.keysym.sym;  // Return the SDL key code
        }
    }
    return 0;  // No input detected
}
