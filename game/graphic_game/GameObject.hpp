#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

/*
This class is a game object is an abstract class that represents an object in the game.
The game object has a position and a size.
The game object can be drawn in a window.
*/ 
class GameObject{
    public:
    virtual ~GameObject() {};
    virtual double posX() = 0;
    virtual double posY() = 0;
    virtual double width() = 0;
    virtual double height() = 0;
};

#endif