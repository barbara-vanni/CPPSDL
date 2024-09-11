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
                run = false;
                windowMenu.getWindowMenu()->close();
                runHowToPlay();
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
    ButtonsSfml button(480, 40, 100, 50, "Reset");
    ButtonsSfml returnMenu(480, 110, 100, 50, "Menu");

    ScoreSfml actualScore(game, 120, 70, "Score");
    ScoreSfml bestScore(game, 280, 70, "Max");



    if (!window.getWindowSfml()->isOpen()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
    }

    game.start();
    bool isRunning = true;
    bool gameOver = false;

    while (isRunning) {
        sf::Event event;
        while (window.getWindowSfml()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
            } else if (event.type == sf::Event::KeyPressed) {
                game.moveSfml(event.key.code);
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (button.isClicked(sf::Mouse::getPosition(*window.getWindowSfml()))) {
                    gameOver = false;
                    game.reset(); 
                }
                if (returnMenu.isClicked(sf::Mouse::getPosition(*window.getWindowSfml()))) {
                    isRunning = false;
                    window.getWindowSfml()->close();
                    gameloop(); 
            }
        }

        if (game.checkDefeat()) {
            gameOver = true; 
        }

        window.clear();
        button.draw(window.getWindowSfml());
        returnMenu.draw(window.getWindowSfml());

        actualScore.draw(window.getWindowSfml());
        bestScore.draw(window.getWindowSfml());
        grid.drawGrid(window.getWindowSfml());
        actualScore.updateActualScore(game.getScoreActuel());
        bestScore.updateBestScore(game.getBestScore());

        if (gameOver) {
            actualScore.drawGameOver(window.getWindowSfml());
        }

        window.getWindowSfml()->display();
    }
    }
}

// Play the game using SDL
void runSdl() {
    WindowSdl windowsdl(600, 800);  

    //     // Load the font for the button
    // TTF_Font* buttonFont = TTF_OpenFont("assets/font/minecraft_font.ttf", 24);
    // if (!buttonFont) {
    //     std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    //     return -1;
    // }
    if (windowsdl.isClosed()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
    }

    Game game;
    GridSdl grid(game);
    ButtonSdl resetButton;
    ScoreSdl Actualscore(game, 160, 90);
    ScoreSdl Bestscore(game, 300, 90);
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
        Actualscore.draw(windowsdl.getRenderer());
        Bestscore.draw(windowsdl.getRenderer());
        Actualscore.updateActualScore(game.getScoreActuel());
        Bestscore.updateBestScore(game.getBestScore());
        resetButton.drawButton(windowsdl.getRenderer(), buttonX, buttonY, buttonWidth, buttonHeight);
        SDL_RenderPresent(windowsdl.getRenderer());
        SDL_Delay(100);
    }
}

// Display the rules of the game
void runHowToPlay() {
    WindowRules windowRules(600, 800);
    if (!windowRules.getWindowRules()->isOpen()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
    }

    bool isRunning = true;
    while (isRunning) {
        sf::Event event;
        while (windowRules.getWindowRules()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
            }
        }

        windowRules.clear();
        windowRules.drawImageRules();
        windowRules.drawTextRules();
        windowRules.getWindowRules()->display();
    }
}