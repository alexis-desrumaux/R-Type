/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../../../../lib/GameCore/include/Objects/Objects.hpp"
#include "../../../../lib/GameCore/include/Object/Object.hpp"

class MenuBehavior : public Behavior
{
    public:
        MenuBehavior(Object *parent);
        ~MenuBehavior();
        void run(std::string key);
    protected:
    private:
    //functions
        void initMenu();
    //data
        Objects *objs;
        bool mounted;
};

class Menu : public Object {
    public:
        Menu(std::string name, Objects *parent);
        ~Menu();
    protected:
    private:
};

#endif /* !MENU_HPP_ */
