#include <SDL2/SDL.h>
#include <iostream>
#include "../game/graphic_game/HPP_files/Window.hpp"
#include "../game/logic_game/HPP_files/BoardSdl.hpp"
#include "game/logic_game/HPP_files/Game.hpp"
#include "game/logic_game/HPP_files/Input.hpp"
#include "game/graphic_game/SFML/HPP_files/WindowSfml.hpp"


int main(int argc, char* argv[]) {
    int choix = 0;
    std::cout << "Choisissez une option:" << std::endl;
    std::cout << "1. Afficher avec SFML" << std::endl;
    std::cout << "2. Lancer le jeu avec SDL" << std::endl;
    std::cin >> choix;

    switch (choix) {
        case 1:
            #include "../game/graphic_game/SFML/HPP_files/WindowSfml.hpp"
            WindowSfml window(600, 800, "SFML Window");

            // printSfml();
            break;

        case 2: {
            // Initialisation de SDL
            Window window(800, 800);
            if (window.isClosed()) {
                std::cerr << "Failed to initialize window" << std::endl;
                return 1;
            }

            BoardSdl board(4);
            const int cellSize = 200; // Ajustez cette taille en fonction de la taille de la fenêtre et du plateau

            bool quit = false;
            SDL_Event event;

            while (!quit) {
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    } else if (event.type == SDL_KEYDOWN) {
                        bool moved = false;
                        switch (event.key.keysym.sym) {
                            case SDLK_UP:
                                moved = board.moveUp();
                                break;
                            case SDLK_DOWN:
                                moved = board.moveDown();
                                break;
                            case SDLK_LEFT:
                                moved = board.moveLeft();
                                break;
                            case SDLK_RIGHT:
                                moved = board.moveRight();
                                break;
                        }
                        if (moved) {
                            board.addRandomTile();
                        }
                    }
                }

                if (!board.okToMove()) {
                    std::cout << "Game Over!" << std::endl;
                    quit = true;
                }

                window.clear();
                board.renderBoard(window.getRenderer(), cellSize);
                SDL_Delay(100); // Ajustez ce délai si nécessaire
            }

            break;
        }

        default:
            std::cout << "Choix invalide." << std::endl;
            break;
    }

    return 0;
}

