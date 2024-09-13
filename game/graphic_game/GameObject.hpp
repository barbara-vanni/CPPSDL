#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

class GameObject{
    public:
    virtual ~GameObject() {};
    virtual double posX() = 0;
    virtual double posY() = 0;
    virtual double width() = 0;
    virtual double height() = 0;
};

#endif