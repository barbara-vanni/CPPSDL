#include "gameloop.hpp"
#include "graphic_game/SFML/HPP_files/WindowMenu.hpp"

void gameloop() {
    bool run = true;
    WindowMenu windowMenu(600, 800);

    while (run) {
        if (windowMenu.isClosed()) {
            run = false;
            break;
        }

        windowMenu.clear();
        WindowMenu::MenuOption selectedOption = windowMenu.drawButtons();
        windowMenu.getWindowMenu()->display();

        switch (selectedOption) {
            case WindowMenu::PLAY:
                run = false; 
                windowMenu.getWindowMenu()->close();
                runSdl();    
                break;

            case WindowMenu::NIGHT_MODE:
                run = false;
                windowMenu.getWindowMenu()->close();
                runSfml();
                break;

            case WindowMenu::HOW_TO_PLAY:
                // runHowToPlay();
                break;

            case WindowMenu::NONE:
            default:
                
                break;
        }
    }
}



// Play the game using SFML
void runSfml() {
    Game game;
    WindowSfml window(600, 800);
    GridSfml grid(game);
    ButtonsSfml button(480, 90, 100, 50, "Reset");

    ScoreSfml actualScore(game, 160, 90, "0");
    ScoreSfml bestScore(game, 300, 90, "0");



    if (!window.getWindowSfml()->isOpen()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
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
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (button.isClicked(sf::Mouse::getPosition(*window.getWindowSfml()))) {
                    game.reset(); 
                }
            }
        }

        window.clear();
        button.draw(window.getWindowSfml());
        actualScore.draw(window.getWindowSfml());
        bestScore.draw(window.getWindowSfml());
        grid.drawGrid(window.getWindowSfml());
        actualScore.updateActualScore(game.getScoreActuel());
        bestScore.updateBestScore(game.getBestScore());
        window.getWindowSfml()->display();
    }
}

// Play the game using SDL
void runSdl() {
    WindowSdl windowsdl(600, 800);  
    if (windowsdl.isClosed()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
    }

    Game game;
    GridSdl grid(game);
    ButtonSdl resetButton;
    int buttonX = 480;
    int buttonY = 70;
    int buttonWidth = 100;
    int buttonHeight = 30;

    game.start();
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
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

            if (resetButton.isClicked(event, buttonX, buttonY, buttonWidth, buttonHeight)) {
                game.reset();  
            }
        }

        windowsdl.clear();
        grid.drawGrid(windowsdl.getRenderer());
        resetButton.drawButton(windowsdl.getRenderer(), buttonX, buttonY, buttonWidth, buttonHeight);
        SDL_RenderPresent(windowsdl.getRenderer());
        SDL_Delay(100);
    }
}