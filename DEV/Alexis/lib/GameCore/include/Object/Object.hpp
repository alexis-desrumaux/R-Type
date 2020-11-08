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
        virtual ~Object() = default;
        std::vector<Components *> &run(std::string key);
        void setGraphical(std::vector<Components *> components);
        std::vector<Components *> &getGraphical();
        Components *findGraphicalComponentByName(std::string);
        void setBehavior(Behavior *behavior);
        Behavior *getBehavior();
        const std::string &getName();
    protected:
    //functions
    //data
        std::string name;
        Objects *parent;
        Behavior *behavior;
        std::vector<Components *> graphical;
    private:
    //functions
    //data

};

#endif /* !OBJECT_HPP_ */
