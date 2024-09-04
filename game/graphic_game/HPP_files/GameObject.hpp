// GameObject.hpp
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SDL2/SDL.h>

class GameObject {
public:
    virtual void draw(SDL_Renderer* renderer) const = 0;
    virtual ~GameObject() = default;
};

#endif // GAMEOBJECT_HPP
