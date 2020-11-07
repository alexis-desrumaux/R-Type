/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "../../../graphical/sfml/include/Components.hpp"
#include "../Behavior/Behavior.hpp"

class Objects;

class Object {
    public:
        Object(std::string name, Objects *parent);
        ~Object();
        std::vector<Components *> &run(std::string key);
        void setGraphical(std::vector<Components *> components);
        std::vector<Components *> &getGraphical();
        void setBehavior(Behavior *behavior);
        Behavior *getBehavior();
    protected:
    //functions
    //data
    private:
    //functions
    //data
        std::string name;
        Objects *parent;
        Behavior *behavior;
        std::vector<Components *> graphical;

};

#endif /* !OBJECT_HPP_ */
