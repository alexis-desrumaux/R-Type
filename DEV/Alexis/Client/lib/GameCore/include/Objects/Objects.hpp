/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Objects
*/

#ifndef OBJECTS_HPP_
#define OBJECTS_HPP_

#include <iostream>
#include <memory>
#include "../Object/Object.hpp"

class Objects {
    public:
    //fonctions
        Objects(Object *parent);
        Objects();
        ~Objects();
        std::vector<std::shared_ptr<Components>> &getGraphicalComponents();
        std::vector<std::shared_ptr<Object>> &grabObjects();
        std::shared_ptr<Object> getObjectByName(std::string);
        Object *getParent();
    //data
    protected:
    private:
    //functions
    //data
        Object *parent;
        std::vector<std::shared_ptr<Components>> graphicalComponents;
        std::vector<std::shared_ptr<Object>> objects;
};

#endif /* !OBJECTS_HPP_ */
