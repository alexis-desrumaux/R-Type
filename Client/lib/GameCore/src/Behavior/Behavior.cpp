/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Behavior
*/

#include "../../include/Behavior/Behavior.hpp"

const std::string &Behavior::getName()
{
    return this->name;
}

Behavior::Behavior(std::string name, Object *parent)
{
    this->parent = parent;
    this->name = name;
}
