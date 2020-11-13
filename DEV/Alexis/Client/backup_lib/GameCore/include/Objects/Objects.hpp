/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Objects
*/

#ifndef OBJECTS_HPP_
#define OBJECTS_HPP_

#include "../Object/Object.hpp"

class Objects {
    public:
    //fonctions
        Objects(Object *parent);
        ~Objects();
        std::vector<Components *> &getGraphicalComponents();
        std::vector<Object *> &grabObjects();
        Object *getObjectByName(std::string);
        Object *getParent();
    //data
    protected:
    private:
    //functions
    //data
        Object *parent;
        std::vector<Components *> graphicalComponents;
        std::vector<Object *> objects;
};

#endif /* !OBJECTS_HPP_ */
