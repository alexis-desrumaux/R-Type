/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Objects
*/

#include "../../include/Objects/Objects.hpp"

Object *Objects::getParent()
{
    return this->parent;
}

std::shared_ptr<Object> Objects::getObjectByName(std::string name)
{
    for (size_t i = 0; i != this->objects.size(); i += 1) {
        if (this->objects.at(i)->getName() == name)
            return (this->objects.at(i));
    }
    return nullptr;
}

std::vector<std::shared_ptr<Object>> &Objects::grabObjects()
{
    return this->objects;
}

std::vector<std::shared_ptr<Components>> &Objects::getGraphicalComponents()
{
    this->graphicalComponents.clear();
    for (int i = 0; i != this->objects.size(); i += 1) {
        this->graphicalComponents.insert(this->graphicalComponents.end(),
            this->objects.at(i)->getGraphical().begin(),
            this->objects.at(i)->getGraphical().end());
    }
    return this->graphicalComponents;
}

Objects::Objects()
{
}

Objects::Objects(Object *parent)
{
    this->parent = parent;
}

Objects::~Objects()
{
    std::cout << "DELETED OBJECTS" << std::endl;
}
