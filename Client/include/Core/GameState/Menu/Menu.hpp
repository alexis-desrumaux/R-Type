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
#include "../../../../lib/graphical/sfml/include/Event.hpp"
#include <iostream>
#include <memory>


#include <sys/time.h>

class UIBehavior : public Behavior
{
    public:
        UIBehavior(Object *parent);
        ~UIBehavior();
        void run(std::shared_ptr<eventType_t> event);
    protected:
    private:
};

class UI : public Object
{
    public:
        UI(std::string name, Objects *parent);
        ~UI();
    protected:
    private:
};

class StartBehavior : public Behavior
{
    public:
        StartBehavior(Object *parent);
        ~StartBehavior();
        void run(std::shared_ptr<eventType_t> event);
    protected:
    private:
    //functions
        void initStart();
        void startAnimation();
    //data
        std::shared_ptr<Component::Text> startTxt;
        std::shared_ptr<myclock_t> startTxtClock;
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
        void run(std::shared_ptr<eventType_t> event);
    protected:
    private:
    //functions
        void initPlanets();
        void movePlanets();
    //data
        std::vector<std::shared_ptr<Component::Sprite>> planets;
        std::shared_ptr<myclock_t> planetsBackgroundClock;
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
        void run(std::shared_ptr<eventType_t> event);
        void enableFasterSpeed();
    protected:
    private:
    //functions
        void initBackground();
        void moveBackground();
        void moveBackground_next();
    //data
        std::shared_ptr<Component::Sprite> background1;
        std::shared_ptr<Component::Sprite> background2;
        std::shared_ptr<Component::Sprite> background3;
        std::shared_ptr<myclock_t> backgroundClock;
        std::shared_ptr<myclock_t> speedClock;
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
        void run(std::shared_ptr<eventType_t> event);
    protected:
    private:
    //functions
        void initMenu();
        void initShips();
    //data
        std::shared_ptr<Objects> objs;
};

class Menu : public Object {
    public:
        Menu(std::string name, Objects *parent);
        ~Menu();
    protected:
    private:
};

#endif /* !MENU_HPP_ */
