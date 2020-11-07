/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Menu
*/

#include "../../../include/Core/GameState/Menu/Menu.hpp"

void MenuBehavior::initMenu()
{
    Object *audio = new Object("audio", this->objs);
    std::vector<Components *> audioComponents;
    audioComponents.push_back(new Component::Audio("audio", "./media/main.ogg", Component::AudioState::PLAY, true));
    audio->setGraphical(audioComponents);

    Object *background = new Object("Background", this->objs);
    std::vector<Components *> backgroundComponents;
    backgroundComponents.push_back(new Component::Sprite("menu_background1", "./media/Menu/menu_background1.jpg", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    background->setGraphical(backgroundComponents);

    Object *title = new Object("title", this->objs);
    std::vector<Components *> titleComponents;
    titleComponents.push_back(new Component::Sprite("menu_title1", "./media/Menu/title1.png", std::pair<float, float>(700, 50), std::pair<float, float>(1.3, 1.3), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    title->setGraphical(titleComponents);

    this->objs->grabObjects().push_back(audio);
    this->objs->grabObjects().push_back(background);
    this->objs->grabObjects().push_back(title);

    this->mounted = true;
}

void MenuBehavior::run(std::string key)
{
    if (this->mounted == false)
        this->initMenu();
    this->parent->setGraphical(this->objs->getGraphicalComponents());
}

MenuBehavior::MenuBehavior(Object *parent) : Behavior(parent)
{
    this->mounted = false;
    this->parent->getGraphical().clear();
    this->objs = new Objects();
}

MenuBehavior::~MenuBehavior()
{

}

Menu::Menu(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = new MenuBehavior(this);
}

Menu::~Menu()
{
    
}
