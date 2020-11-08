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
#include <sys/time.h>

struct myclock_t
{
    struct timeval start;
    struct timeval end;
};

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
        void initShips();
        void moveBackground();
        void moveBackground_next(Object *background);
    //data
        Objects *objs;
        myclock_t *backgroundClock;
};

class Menu : public Object {
    public:
        Menu(std::string name, Objects *parent);
        ~Menu();
    protected:
    private:
};

#endif /* !MENU_HPP_ */
