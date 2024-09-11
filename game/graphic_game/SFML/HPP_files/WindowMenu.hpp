// #ifndef WINDOWMENU_HPP
// #define WINDOWMENU_HPP
// #include "../../src/include/SFML/Graphics.hpp"
// #include "../../src/include/SFML/Window/Event.hpp"
// #include <iostream>
// #include <memory>

// class WindowMenu {
//     private: 
//         bool init();
//         std::unique_ptr<sf::RenderWindow> Window;
//         std::unique_ptr<sf::RectangleShape> rectangle;
//         int width;
//         int height;
//         std::string title;
//         bool closed;

//     public:
//     WindowMenu(int width = 600, int height = 800);
//     ~WindowMenu() = default; 
//     void clear() const;
//     bool isClosed();
//     enum MenuOption {NONE, PLAY, NIGHT_MODE, HOW_TO_PLAY};
//     MenuOption drawButtons();
//     sf::RenderWindow* getWindowMenu() const;
// };

// #endif 