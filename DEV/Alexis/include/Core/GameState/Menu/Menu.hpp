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
#include "../../../../lib/GameCore/include/Tools/Tools.hpp"

#include <sys/time.h>

class StartBehavior : public Behavior
{
    public:
        StartBehavior(Object *parent);
        ~StartBehavior();
        void run(std::string &keyPressed);
    protected:
    private:
    //functions
        void initStart();
        void startAnimation();
    //data
        Component::Text *startTxt;
        myclock_t *startTxtClock;
        bool startTxtToogle;
};

class Start : public Object
{
    public:
        Start(std::string name, Objects *parent);
        ~Start();
    protected:
    private:
};

class PlanetsBehavior : public Behavior
{
    public:
        PlanetsBehavior(Object *parent);
        ~PlanetsBehavior();
        void run(std::string &key);
    protected:
    private:
    //functions
        void initPlanets();
        void movePlanets();
    //data
        std::vector<Component::Sprite *> planets;
        myclock_t *planetsBackgroundClock;
        bool enableFasterSpeed;
};

class Planets : public Object
{
    public:
        Planets(std::string name, Objects *parent);
        ~Planets();
    protected:
    private:
};

class BackgroundBehavior : public Behavior
{
    public:
        BackgroundBehavior(Object *parent);
        ~BackgroundBehavior();
        void run(std::string &key);
        void enableFasterSpeed();
    protected:
    private:
    //functions
        void initBackground();
        void moveBackground();
        void moveBackground_next();
    //data
        Component::Sprite *background1;
        Component::Sprite *background2;
        Component::Sprite *background3;
        myclock_t *backgroundClock;
        myclock_t *speedClock;
        float speed;
        bool enableFasterSpeedToogle;

};

class Background : public Object
{
    public:
        Background(std::string name, Objects *parent);
        ~Background();
    protected:
    private:
};

class MenuBehavior : public Behavior
{
    public:
        MenuBehavior(Object *parent);
        ~MenuBehavior();
        void run(std::string &key);
    protected:
    private:
    //functions
        void initMenu();
        void initShips();
    //data
        Objects *objs;
};

class Menu : public Object {
    public:
        Menu(std::string name, Objects *parent);
        ~Menu();
    protected:
    private:
};

#endif /* !MENU_HPP_ */
