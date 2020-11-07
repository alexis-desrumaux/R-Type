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
        Objects();
        ~Objects();
        std::vector<Components *> &getGraphicalComponents();
        std::vector<Object *> &grabObjects();
    //data
    protected:
    private:
    //functions
    //data
        std::vector<Components *> graphicalComponents;
        std::vector<Object *> objects;
};

#endif /* !OBJECTS_HPP_ */
