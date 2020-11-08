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
        void movePlanets();
        void startAnimation();
        void moveBackground_next(Object *background);
    //data
        Objects *objs;
        Component::Sprite *earthBackground;
        Component::Sprite *marsBackground;
        Component::Text *startTxt;
        myclock_t *backgroundClock;
        myclock_t *planetsBackgroundClock;
        myclock_t *startTxtClock;
        bool startTxtToogle;
};

class Menu : public Object {
    public:
        Menu(std::string name, Objects *parent);
        ~Menu();
    protected:
    private:
};

#endif /* !MENU_HPP_ */
