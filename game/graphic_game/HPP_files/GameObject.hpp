// GameObject.hpp
#pragma once
#include <SDL2/SDL.h>


class GameObject {
public:
    virtual double posX(double x ) = 0 ;
    virtual double posY(double y)  = 0 ;
    virtual int size(int size)  = 0 ;
    virtual ~GameObject() {}
};