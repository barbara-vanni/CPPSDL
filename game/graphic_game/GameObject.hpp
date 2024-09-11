#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP


/*This class is mother of every object who s drawed in the UI*/
class GameObject{
    public:
    virtual ~GameObject() {};
    virtual double posX() = 0;
    virtual double posY() = 0;
    virtual double width() = 0;
    virtual double height() = 0;
};

#endif