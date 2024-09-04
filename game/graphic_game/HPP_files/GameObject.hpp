#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SDL2/SDL.h>

class GameObject {
public:
    GameObject(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

    virtual ~GameObject() {}

    // Virtual method for rendering the object
    virtual void render(SDL_Renderer* renderer) const = 0;

    // Virtual method for updating object properties, if necessary
    virtual void update() = 0;

    // Setters and getters for position and dimensions
    int getX() const { return x; }
    void setX(int x) { this->x = x; }

    int getY() const { return y; }
    void setY(int y) { this->y = y; }

    int getWidth() const { return width; }
    void setWidth(int width) { this->width = width; }

    int getHeight() const { return height; }
    void setHeight(int height) { this->height = height; }

protected:
    int x, y;
    int width, height;
};

#endif // GAMEOBJECT_HPP
