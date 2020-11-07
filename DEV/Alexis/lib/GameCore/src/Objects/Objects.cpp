/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Objects
*/

#include "../../include/Objects/Objects.hpp"

std::vector<Object *> &Objects::grabObjects()
{
    return this->objects;
}

std::vector<Components *> &Objects::getGraphicalComponents()
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

Objects::~Objects()
{
}
