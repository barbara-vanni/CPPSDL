// GameObject.hpp
#pragma once
#include <SDL2/SDL.h>


class GameObject {
public:
    virtual double setPosX(double x ) = 0 ;
    virtual double setPosY(double y)  = 0 ;
    virtual int setCellSize(int size)  = 0 ;
    virtual ~GameObject() {}
};

