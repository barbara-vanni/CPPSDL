// GameObject.hpp
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SDL2/SDL.h>


class GameObject {
public:
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual ~GameObject() {}
};

#endif // GAMEOBJECT_HPP
