/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GLib
*/

#ifndef IGLIB_HPP_
#define IGLIB_HPP_

#include <iostream>
#include <memory>
#include <fstream>
#include "Components.hpp"
#include "Event.hpp"

class IGLib {
    public:
    //functions
        IGLib() = default;
        virtual ~IGLib() = default;
        virtual std::shared_ptr<eventType_t> display(std::vector<std::shared_ptr<Components>>) = 0;
        std::string name;
        int state;
    //settings
        bool isRunning;
        std::string type;
    protected:
    private:
};

#endif /* !IGLIB_HPP_ */
