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
        virtual ~Object();
        std::vector<std::shared_ptr<Components>> &run(std::shared_ptr<eventType_t> event);
        void setGraphical(std::vector<std::shared_ptr<Components>> components);
        std::vector<std::shared_ptr<Components>> &getGraphical();
        std::shared_ptr<Components> findGraphicalComponentByName(std::string);
        void setBehavior(std::shared_ptr<Behavior> behavior);
        std::shared_ptr<Behavior> getBehavior();
        const std::string &getName();
        Objects *getParent();
    protected:
    //functions
    //data
        Objects *parent;
        std::string name;
        std::shared_ptr<Behavior> behavior;
        std::vector<std::shared_ptr<Components>> graphical;
    private:
    //functions
    //data

};

#endif /* !OBJECT_HPP_ */
