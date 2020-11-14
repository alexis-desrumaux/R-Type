/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Object
*/

#include "../../include/Object/Object.hpp"

Objects *Object::getParent()
{
    return this->parent;
}

const std::string &Object::getName()
{
    return this->name;
}

std::shared_ptr<Behavior> Object::getBehavior()
{
    return this->behavior;
}

void Object::setBehavior(std::shared_ptr<Behavior> behavior)
{
    this->behavior = behavior;
}

std::shared_ptr<Components> Object::findGraphicalComponentByName(std::string name)
{
    for (size_t i = 0; i != this->graphical.size(); i += 1) {
        if (this->graphical.at(i)->componentName == name)
            return this->graphical.at(i);
    }
    return NULL;
}

std::vector<std::shared_ptr<Components>> &Object::getGraphical()
{
    return this->graphical;
}

void Object::setGraphical(std::vector<std::shared_ptr<Components>> components)
{
    this->graphical = components;
}

std::vector<std::shared_ptr<Components>> &Object::run(std::shared_ptr<eventType_t> event)
{
    if (this->behavior != NULL) {
        this->behavior->run(event);
    }
    return this->graphical;
}

Object::Object(std::string name, Objects *parent)
{
    this->name = name;
    this->parent = parent;
    this->behavior = NULL;
}

Object::~Object()
{
    //std::cout << "DESTROYED OBJECT " << this->name << std::endl;

    /*if (!this->behavior)
        delete this->behavior;
    for (size_t i = 0; i != this->graphical.size(); i += 1) {
        if (!this->graphical.at(i))
            delete this->graphical.at(i);
    }*/
}
