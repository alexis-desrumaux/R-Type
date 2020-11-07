/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Object
*/

#include "../../include/Object/Object.hpp"

const std::string &Object::getName()
{
    return this->name;
}

Behavior *Object::getBehavior()
{
    return this->behavior;
}

void Object::setBehavior(Behavior *behavior)
{
    this->behavior = behavior;
}

std::vector<Components *> &Object::getGraphical()
{
    return this->graphical;
}

void Object::setGraphical(std::vector<Components *> components)
{
    this->graphical = components;
}

std::vector<Components *> &Object::run(std::string key)
{
    if (this->behavior != nullptr) {
        this->behavior->run(key);
    }
    return this->graphical;
}

Object::Object(std::string name, Objects *parent)
{
    this->name = name;
    this->parent = parent;
    this->behavior = NULL;
}
