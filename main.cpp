#include "SDL2/SDL.h"
#include <iostream>
#include "../game/logic_game/HPP_files/BoardSdl.hpp"
#include "game/logic_game/HPP_files/Game.hpp"
#include "game/logic_game/HPP_files/Input.hpp"
#include "game/graphic_game/HPP_files/ButtonSdl.hpp"
// #include "game/graphic_game/SFML/HPP_files/WindowSfml.hpp"
// #include "game/graphic_game/SFML/HPP_files/GridSfml.hpp"
// #include "game/graphic_game/SFML/HPP_files/TilesSfml.hpp"
#include "../game/graphic_game/HPP_files/Window.hpp"
#include "../game/graphic_game/HPP_files/GridSdl.hpp"
#include "../game/graphic_game/HPP_files/TilesSdl.hpp"

#include "game/graphic_game/SFML/HPP_files/GridSfml.hpp"
#include "game/graphic_game/SFML/HPP_files/TilesSfml.hpp"
#include "game/graphic_game/SFML/HPP_files/WindowSfml.hpp"


int main(int argc, char* argv[]) {
    int choice = 0;
    std::cout << "Choisissez une option:" << std::endl;
    std::cout << "1. Afficher avec SFML" << std::endl;
    std::cout << "2. Lancer le jeu avec SDL" << std::endl;
    std::cin >> choice;


    switch (choice) {

        case 1: {
            Game game;
            WindowSfml window(600, 800);
            GridSfml grid(game);

            if (!window.getWindowSfml()->isOpen()) {
                std::cerr << "Failed to initialize window" << std::endl;
                return 1;
            }

            game.start();

            bool isRunning = true;

            while (isRunning) {
                sf::Event event;
                while (window.getWindowSfml()->pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        isRunning = false; 
                    } else if (event.type == sf::Event::KeyPressed) {
                        game.moveSfml(event.key.code); 
                    }
                }

                window.clear();

                grid.drawGrid(window.getWindowSfml());
                window.getWindowSfml()->display();
            }

            break;
        }


        case 2: {
            // Initialize SDL and create a window
            Window window(600, 800);  // Window dimensions
            if (window.isClosed()) {
                std::cerr << "Failed to initialize window" << std::endl;
                return 1;
            }

            // Create the game and grid objects
            Game game;
            GridSdl grid(game);
            ButtonSdl resetButton;

            // Set the button dimensions and position (example: bottom of the window)
            int buttonX = 480;
            int buttonY = 70;
            int buttonWidth = 100;
            int buttonHeight = 30;

            // Start the game logic
            game.start();

            // Main game loop
            bool quit = false;
            SDL_Event event;

            while (!quit) {
                // Polling events
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    } 
                    else if (event.type == SDL_KEYDOWN) {
                        // Handle key press events
                        switch (event.key.keysym.sym) {
                            case SDLK_UP:
                                game.moveSdl(SDLK_UP);
                                break;
                            case SDLK_DOWN:
                                game.moveSdl(SDLK_DOWN);
                                break;
                            case SDLK_LEFT:
                                game.moveSdl(SDLK_LEFT);
                                break;
                            case SDLK_RIGHT:
                                game.moveSdl(SDLK_RIGHT);
                                break;
                            case SDLK_ESCAPE:
                                quit = true;
                                break;
                        }
                    }

                    // Check if the reset button is clicked
                    if (resetButton.isClicked(event, buttonX, buttonY, buttonWidth, buttonHeight)) {
                        game.reset();  // Call the reset function in the Game class
                    }
                }

                // Render the window contents
                window.clear();  // Clear the screen

                // Draw the grid and reset button
                grid.drawGrid(window.getRenderer());
                resetButton.drawButton(window.getRenderer(), buttonX, buttonY, buttonWidth, buttonHeight);

                // Update the screen
                SDL_RenderPresent(window.getRenderer());
                SDL_Delay(100);  // Delay for smoother frame rendering
            }

            break;
        }


        default:
            std::cout << "Choix invalide." << std::endl;
            break;
    }

    return 0;
}