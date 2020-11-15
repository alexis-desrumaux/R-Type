/*
** EPITECH PROJECT, 2020
** IGame.hpp
** File description:
** IGame
*/

#ifndef _IGAME_HPP_
# define _IGAME_HPP_

#include "Object.hpp"

class IGame
{
public:
    virtual ~IGame() {};
    virtual size_t getWindowSizeX() const = 0;
    virtual size_t getWindowSizeY() const = 0;
    virtual std::string getWindowName() const = 0;
    virtual std::vector<size_t> getCreateEntity() const = 0;
    virtual std::vector<size_t> getDeleteEntity() const = 0;
    virtual std::vector<size_t> getAllEntity() const = 0;
    virtual std::map<size_t, Object *> getEntity() const = 0;
    virtual std::string getMessage() = 0;

    virtual void updateRtype() = 0;
};

#endif
