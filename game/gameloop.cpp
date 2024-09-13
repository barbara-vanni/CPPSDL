#include "gameloop.hpp"
#include "graphic_game/SFML/HPP_files/WindowMenu.hpp"

/*
This function is the main function of the game, it will call the function that will run the game
This function will also display the main menu of the game
This function will also display the rules of the game
This function will also display the game using SFML
This function will also display the game using SDL
*/ 
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
        actualScore.updateActualScore(game.getActualScore());
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

    if (windowsdl.isClosed()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
    }

    Game game;  
    GridSdl grid(game); 
    ButtonSdl resetButton; 
    ButtonSdl returnMenu;   

    ScoreSdl Actualscore(game, 120, 50, "Score");
    ScoreSdl Bestscore(game, 280, 50, "Max");
    ScoreSdl Defeat(game, 300, 400, "Game Over");

    int buttonX = 480;
    int buttonY = 70;
    int buttonWidth = 100;
    int buttonHeight = 30;

    game.start();  
    bool gameOver = false;
    SDL_Event event;


    while (!windowsdl.isClosed()) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                windowsdl.close(); 
                break;
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
                        windowsdl.close();  
                        break;
                }
            }

            if (resetButton.isClicked(event, buttonX, buttonY, buttonWidth, buttonHeight)) {
                game.reset();  
                gameOver = false;  
            }

            if (returnMenu.isClicked(event, buttonX, buttonY + 60, buttonWidth + 10, buttonHeight)) {
                windowsdl.close(); 
                std::cout << "Return to menu" << std::endl;
                gameloop();  
            }

            if (game.checkDefeat()) {
                gameOver = true;
            }
        }

        windowsdl.clear();  
        grid.drawGrid(windowsdl.getRenderer()); 
        Actualscore.updateActualScore(game.getActualScore());
        Bestscore.updateBestScore(game.getBestScore());  

        Actualscore.draw(windowsdl.getRenderer()); 
        Bestscore.draw(windowsdl.getRenderer());  
        resetButton.drawButton(windowsdl.getRenderer(), buttonX, buttonY, buttonWidth, buttonHeight, "Reset");
        returnMenu.drawButton(windowsdl.getRenderer(), buttonX, buttonY +60 , buttonWidth + 10, buttonHeight, "Menu"); 
        if (gameOver) {
            Defeat.drawDefeat(windowsdl.getRenderer());
        }

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