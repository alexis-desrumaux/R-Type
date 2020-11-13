/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "../../../graphical/sfml/include/Components.hpp"
#include "../../../graphical/sfml/include/Event.hpp"
#include "../Behavior/Behavior.hpp"

class Objects;

class Object {
    public:
        Object(std::string name, Objects *parent);
        virtual ~Object() = default;
        std::vector<Components *> &run(eventType_t *event);
        void setGraphical(std::vector<Components *> components);
        std::vector<Components *> &getGraphical();
        Components *findGraphicalComponentByName(std::string);
        void setBehavior(Behavior *behavior);
        Behavior *getBehavior();
        const std::string &getName();
        Objects *getParent();
    protected:
    //functions
    //data
        Objects *parent;
        std::string name;
        Behavior *behavior;
        std::vector<Components *> graphical;
    private:
    //functions
    //data

};

#endif /* !OBJECT_HPP_ */
