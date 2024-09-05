// #ifndef WINDOW_HPP
// #define WINDOW_HPP

// #include <../../../../src/include/SFML/Graphics/RenderWindow.hpp>
// #include <../../../../src/include/SFML/Graphics/RectangleShape.hpp>
// #include <../../../../src/include/SFML/Window/Event.hpp>
// #include <iostream>
// #include <memory>

// class WindowSfml {
//     private: +
//         bool init();
//         std::unique_ptr<sf::RenderWindow> window;
//         std::unique_ptr<sf::RectangleShape> rectangle;
//         int width;
//         int height;
//         std::string title;
//         bool closed;

//     public:
//     WindowSfml(int width = 600, int height = 800);
//     WindowSfml(const std::string &title, int width = 600, int height = 800);
//     ~WindowSfml() = default; 
//     void clear() const;
//     bool isClosed();
//     sf::RenderWindow* getWindow() const;
// };

// #endif 