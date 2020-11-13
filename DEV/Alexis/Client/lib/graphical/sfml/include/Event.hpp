/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <iostream>
#include "./SFMLTools.hpp"

namespace Mouse
{
    namespace Button
    {
        enum Type
        {
            LEFT,
            MIDDLE,
            RIGHT,
            NONE,
        };
    };
};

enum mouseButtonPressedType
{
    
};

struct eventType_t
{
    bool isMouseBtnPressed;
    bool isMouseBtnReleased;
    bool isMouseMoved;
    bool isKeyPressed;
    bool isKeyReleased;
    bool isClosed;
    Mouse::Button::Type mouseButtonPressedType;
    std::string keyPressed;
    Point2D mouseCoordinates;
    Point2D mouseButtonPressedCoordinates;
};

#endif /* !COMMAND_HPP_ */
