#include "../HPP_files/Input.hpp"
#include <stdio.h>
#include "SDL2/SDL.h"
#include "conio.h"
// #include <ncurses.h>
#include <iostream>

/*
This class is used to get the input from the user
*/ 

// Constructor
Input::Input() {
    std::cout << "Constructor called" << std::endl;
}

// Destructor
Input::~Input() {
    std::cout << "Destructor called" << std::endl;
}

// Get the input from the user
int Input::getInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            return event.key.keysym.sym;  
        }
    }
    return 0; 
}
