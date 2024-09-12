#include "gameloop.hpp"
#include "graphic_game/SFML/HPP_files/WindowMenu.hpp"

/* The function initializes the game window and menu, and continuously checks for user inputs and updates the game state accordingly.
 It uses the SFML library to play the game and provides options to switch to SDL or view the game rules.
 The game loop continues until the user chooses to exit the game or switch to a different mode.
 */
void gameloop() {
    bool run = true;
    WindowMenu windowMenu(600, 800);

    while (run) {
        if (windowMenu.isClosed()) {
        run = false; 
        break;
        }
    
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
    WindowSdl windowsdl(600, 800); // Initialize SDL window (width 600, height 800)

    WindowSdl windowsdl(600, 800); // Initialize SDL window (width 600, height 800)

    if (windowsdl.isClosed()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return;
    }

    Game game;  // Game instance
    GridSdl grid(game);  // Grid instance to draw the game grid
    ButtonSdl resetButton;  // Button to reset the game
    ButtonSdl returnMenu;   // Button to return to the main menu

    // Initialize score displays
    ScoreSdl Actualscore(game, 120, 50, "Score");
    ScoreSdl Bestscore(game, 280, 50, "Max");
    ScoreSdl Defeat(game, 300, 400, "Game Over");

    // Button properties
    Game game;  // Game instance
    GridSdl grid(game);  // Grid instance to draw the game grid
    ButtonSdl resetButton;  // Button to reset the game
    ButtonSdl returnMenu;   // Button to return to the main menu

    // Initialize score displays
    ScoreSdl Actualscore(game, 120, 50, "Score");
    ScoreSdl Bestscore(game, 280, 50, "Max");
    ScoreSdl Defeat(game, 300, 400, "Game Over");

    // Button properties
    int buttonX = 480;
    int buttonY = 70;
    int buttonWidth = 100;
    int buttonHeight = 30;

    game.start();  // Start the game
    game.start();  // Start the game
    bool gameOver = false;
    SDL_Event event;  // Event structure for handling user inputs

    while (!windowsdl.isClosed()) {
    while (!windowsdl.isClosed()) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                windowsdl.close();  // Close the window properly
                break;
                windowsdl.close();  // Close the window properly
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
                        windowsdl.close();  // Quit when ESC is pressed
                        windowsdl.close();  // Quit when ESC is pressed
                        break;
                }
            }

            // Check if the reset button is clicked
            // Check if the reset button is clicked
            if (resetButton.isClicked(event, buttonX, buttonY, buttonWidth, buttonHeight)) {
                game.reset();  
                gameOver = false;  // Reset the game-over state
                gameOver = false;  // Reset the game-over state
            }

            // Check if the return to menu button is clicked

            // Check if the return to menu button is clicked
            if (returnMenu.isClicked(event, buttonX, buttonY + 60, buttonWidth + 10, buttonHeight)) {
                windowsdl.close();  // Close the window properly
                std::cout << "Return to menu" << std::endl;
                gameloop();  // Relaunch the game loop
                windowsdl.close();  // Close the window properly
                std::cout << "Return to menu" << std::endl;
                gameloop();  // Relaunch the game loop
            }

            // Check for game-over condition
            // Check for game-over condition
            if (game.checkDefeat()) {
                gameOver = true;
            }
        }

        windowsdl.clear();  // Clear the window before rendering
        grid.drawGrid(windowsdl.getRenderer());  // Draw the game grid
        Actualscore.updateActualScore(game.getScoreActuel());  // Update the actual score display
        Bestscore.updateBestScore(game.getBestScore());  // Update the best score display

        Actualscore.draw(windowsdl.getRenderer());  // Draw the actual score
        Bestscore.draw(windowsdl.getRenderer());  // Draw the best score
        resetButton.drawButton(windowsdl.getRenderer(), buttonX, buttonY, buttonWidth, buttonHeight, "Reset");  // Draw reset button
        returnMenu.drawButton(windowsdl.getRenderer(), buttonX, buttonY +60 , buttonWidth + 10, buttonHeight, "Menu"); // Draw return menu button

        windowsdl.clear();  // Clear the window before rendering
        grid.drawGrid(windowsdl.getRenderer());  // Draw the game grid
        Actualscore.updateActualScore(game.getScoreActuel());  // Update the actual score display
        Bestscore.updateBestScore(game.getBestScore());  // Update the best score display

        Actualscore.draw(windowsdl.getRenderer());  // Draw the actual score
        Bestscore.draw(windowsdl.getRenderer());  // Draw the best score
        resetButton.drawButton(windowsdl.getRenderer(), buttonX, buttonY, buttonWidth, buttonHeight, "Reset");  // Draw reset button
        returnMenu.drawButton(windowsdl.getRenderer(), buttonX, buttonY +60 , buttonWidth + 10, buttonHeight, "Menu"); // Draw return menu button

        if (gameOver) {
            Defeat.drawDefeat(windowsdl.getRenderer());  // Draw game-over screen if the game is over
            Defeat.drawDefeat(windowsdl.getRenderer());  // Draw game-over screen if the game is over
        }

        SDL_RenderPresent(windowsdl.getRenderer());  // Update the window with new render
        SDL_Delay(100);  // Control the frame rate

        SDL_RenderPresent(windowsdl.getRenderer());  // Update the window with new render
        SDL_Delay(100);  // Control the frame rate
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