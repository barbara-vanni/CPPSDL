#include "../HPP_files/Input.hpp"
#include <stdio.h>
#include <conio.h>
#include <iostream>

Input::Input() {
    std::cout << "Constructor called" << std::endl;
}

Input::~Input() {
    std::cout << "Destructor called" << std::endl;
}

int Input::getInput() {
    char input = getch();

    if (input == 27) {  
        std::cout << "Exit" << std::endl;
        return 27;
    } else if (input == -32) { 
        input = getch();
        switch (input) {
        case 72:
            std::cout << "Up" << std::endl;
            break;
        case 80:
            std::cout << "Down" << std::endl;
            break;
        case 75:
            std::cout << "Left" << std::endl;
            break;
        case 77:
            std::cout << "Right" << std::endl;
            break;
        default:
            std::cout << "Press arrow keys to move the tiles or ESC to quit" << std::endl;
            break;
        }
    } else {
        std::cout << "Press arrow keys to move the tiles or ESC to quit" << std::endl;
    }
    return input;
}
