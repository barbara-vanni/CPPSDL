// GameObject.hpp
#pragma once



class GameObject {
public:
    virtual double posX() = 0 ;
    virtual double posY()  = 0 ;
    virtual double width() = 0 ;
    virtual double height() = 0 ;
    virtual ~GameObject() {}
};