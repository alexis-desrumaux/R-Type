/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Behavior
*/

#ifndef BEHAVIOR_HPP_
#define BEHAVIOR_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include "../../../graphical/sfml/include/Event.hpp"

class Object;

class Behavior {
    public:
    //functions
        Behavior(std::string name, Object *parent);
        virtual ~Behavior() = default;
        virtual void run(std::shared_ptr<eventType_t> event) = 0;
        const std::string &getName();
    //data
    protected:
    //functions
    //data
        Object *parent;
        std::string name;
    private:
};

#endif /* !BEHAVIOR_HPP_ */
