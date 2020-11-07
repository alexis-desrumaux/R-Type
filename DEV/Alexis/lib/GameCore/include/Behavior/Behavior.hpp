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

class Object;

class Behavior {
    public:
    //functions
        Behavior(Object *parent);
        virtual ~Behavior() = default;
        virtual void run(std::string key) = 0;
        const std::string &getType();
    //data
    protected:
    //functions
    //data
        Object *parent;
        std::string type;
    private:
};

#endif /* !BEHAVIOR_HPP_ */
