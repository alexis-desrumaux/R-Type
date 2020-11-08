/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Menu
*/

#include "../../../include/Core/GameState/Menu/Menu.hpp"

long getElapsedTime_millisec(myclock_t *clock)
{
    long seconds, millisec, useconds = 0;
    gettimeofday(&clock->end, NULL);
    seconds = clock->end.tv_sec - clock->start.tv_sec; //seconds
    useconds = clock->end.tv_usec - clock->start.tv_usec; //milliseconds
    millisec = ((seconds) * 1000 + useconds/1000.0);
    return millisec;
}

void MenuBehavior::startAnimation()
{
    if (getElapsedTime_millisec(this->startTxtClock) < 1000)
        return;
    this->startTxtToogle = !this->startTxtToogle;
    this->startTxt->display = this->startTxtToogle;
    this->startTxt->setState(Component::State::UPDATE);
    gettimeofday(&this->startTxtClock->start, NULL);
}

void MenuBehavior::movePlanets()
{
    std::pair<float, float> earthBackgroundSpritePos;
    std::pair<float, float> marsBackgroundSpritePos;

    if (getElapsedTime_millisec(this->planetsBackgroundClock) < 1)
        return;
    if (this->earthBackground == NULL || this->marsBackground == NULL)
        return;
    earthBackgroundSpritePos = this->earthBackground->getPosition();
    marsBackgroundSpritePos = this->marsBackground->getPosition();
    earthBackgroundSpritePos.first -= 2;
    marsBackgroundSpritePos.first -= 2;
    earthBackground->setPosition(earthBackgroundSpritePos);
    marsBackground->setPosition(marsBackgroundSpritePos);
    earthBackground->setState(Component::State::UPDATE);
    marsBackground->setState(Component::State::UPDATE);
    gettimeofday(&this->planetsBackgroundClock->start, NULL);
}

void MenuBehavior::moveBackground_next(Object *background)
{
    Components *backgroundComponent = background->findGraphicalComponentByName("menu_background1");
    Components *backgroundComponent2 = background->findGraphicalComponentByName("menu_background2");
    Components *backgroundComponent3 = background->findGraphicalComponentByName("menu_background3");
    Component::Sprite *backgroundSprite = NULL;
    Component::Sprite *backgroundSprite2 = NULL;
    Component::Sprite *backgroundSprite3 = NULL;
    std::pair<float, float> backgroundSpritePos;
    std::pair<float, float> backgroundSpritePos2;
    std::pair<float, float> backgroundSpritePos3;

    if (backgroundComponent != NULL) {
        if (backgroundComponent->type == listComponent::SPRITE) {
            backgroundSprite = dynamic_cast<Component::Sprite *>(backgroundComponent);
        }
    }
    if (backgroundComponent2 != NULL) {
        if (backgroundComponent2->type == listComponent::SPRITE) {
            backgroundSprite2 = dynamic_cast<Component::Sprite *>(backgroundComponent2);
        }
    }
    if (backgroundComponent3 != NULL) {
        if (backgroundComponent3->type == listComponent::SPRITE) {
            backgroundSprite3 = dynamic_cast<Component::Sprite *>(backgroundComponent3);
        }
    }
    if (backgroundSprite == NULL || backgroundSprite2 == NULL || backgroundSprite3 == NULL)
        return;
    backgroundSpritePos = backgroundSprite->getPosition();
    backgroundSpritePos2 = backgroundSprite2->getPosition();
    backgroundSpritePos3 = backgroundSprite3->getPosition();

    if (backgroundSpritePos2.first <= 0) {
        backgroundSpritePos.first = 0;
        backgroundSpritePos2.first = 1920;
        backgroundSpritePos3.first = 3840;
    }
    backgroundSpritePos.first -= 1;
    backgroundSpritePos2.first -= 1;
    backgroundSpritePos3.first -= 1;
    backgroundSprite->setPosition(backgroundSpritePos);
    backgroundSprite2->setPosition(backgroundSpritePos2);
    backgroundSprite3->setPosition(backgroundSpritePos2);
    backgroundSprite->setState(Component::State::UPDATE);
    backgroundSprite2->setState(Component::State::UPDATE);
    backgroundSprite3->setState(Component::State::UPDATE);
}

void MenuBehavior::moveBackground()
{
    Object *background;

    if (getElapsedTime_millisec(this->backgroundClock) >= 1) {
        background = this->objs->getObjectByName("Background");
        if (background != NULL)
            this->moveBackground_next(background);
        gettimeofday(&this->backgroundClock->start, NULL);
    }
}

void MenuBehavior::run(std::string key)
{
    this->moveBackground();
    this->movePlanets();
    this->startAnimation();
    this->parent->setGraphical(this->objs->getGraphicalComponents());
}

void MenuBehavior::initShips()
{
    Object *redShip = new Object("redShip", this->objs);
    std::vector<Components *> redShipComponents;
    redShipComponents.push_back(new Component::Sprite("menu_redShip", "./media/ship.png", std::pair<float, float>(500, 500), std::pair<float, float>(0.7, 0.7), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    redShip->setGraphical(redShipComponents);

    Object *yellowShip = new Object("yellowShip", this->objs);
    std::vector<Components *> yellowShipComponents;
    yellowShipComponents.push_back(new Component::Sprite("menu_yellowShip", "./media/ship2.png", std::pair<float, float>(100, 500), std::pair<float, float>(0.7, 0.7), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    yellowShip->setGraphical(yellowShipComponents);

    Object *greenShip = new Object("greenShip", this->objs);
    std::vector<Components *> greenShipComponents;
    greenShipComponents.push_back(new Component::Sprite("menu_greenShip", "./media/ship3.png", std::pair<float, float>(250, 300), std::pair<float, float>(0.7, 0.7), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    greenShip->setGraphical(greenShipComponents);

    Object *blueShip = new Object("blueShip", this->objs);
    std::vector<Components *> blueShipComponents;
    blueShipComponents.push_back(new Component::Sprite("menu_blueShip", "./media/ship4.png", std::pair<float, float>(250, 700), std::pair<float, float>(0.7, 0.7), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    blueShip->setGraphical(blueShipComponents);

    this->objs->grabObjects().push_back(redShip);
    this->objs->grabObjects().push_back(yellowShip);
    this->objs->grabObjects().push_back(greenShip);
    this->objs->grabObjects().push_back(blueShip);
}

void MenuBehavior::initMenu()
{
    Object *audio = new Object("audio", this->objs);
    std::vector<Components *> audioComponents;
    audioComponents.push_back(new Component::Audio("audio", "./media/main.ogg", Component::AudioState::PLAY, true));
    audio->setGraphical(audioComponents);

    Object *background = new Object("Background", this->objs);
    std::vector<Components *> backgroundComponents;
    backgroundComponents.push_back(new Component::Sprite("menu_background1", "./media/Menu/menu_background1.jpg", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    backgroundComponents.push_back(new Component::Sprite("menu_background2", "./media/Menu/menu_background1.jpg", std::pair<float, float>(1920, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    backgroundComponents.push_back(new Component::Sprite("menu_background3", "./media/Menu/menu_background1.jpg", std::pair<float, float>(3840, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->earthBackground = new Component::Sprite("menu_earth", "./media/Menu/earth.png", std::pair<float, float>(1920, 400), std::pair<float, float>(0.5, 0.5), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    backgroundComponents.push_back(this->earthBackground);
    this->marsBackground = new Component::Sprite("menu_mars", "./media/Menu/mars.png", std::pair<float, float>(4340, 300), std::pair<float, float>(0.3, 0.3), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    backgroundComponents.push_back(this->marsBackground);
    background->setGraphical(backgroundComponents);

    Object *title = new Object("title", this->objs);
    std::vector<Components *> titleComponents;
    titleComponents.push_back(new Component::Sprite("menu_title1", "./media/Menu/title1.png", std::pair<float, float>(700, 50), std::pair<float, float>(1.3, 1.3), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    title->setGraphical(titleComponents);

    Object *start = new Object("start", this->objs);
    std::vector<Components *> startComponents;
    this->startTxt = new Component::Text("menu_startTxt", "START", "./media/Fonts/arcade.ttf", 60, Component::Color::White, std::pair<float, float>(800, 500), std::pair<int, int>(-1, -1));
    startComponents.push_back(this->startTxt);
    start->setGraphical(startComponents);

    this->objs->grabObjects().push_back(audio);
    this->objs->grabObjects().push_back(background);
    this->objs->grabObjects().push_back(title);
    this->initShips();
    this->objs->grabObjects().push_back(start);
}

MenuBehavior::MenuBehavior(Object *parent) : Behavior(parent)
{
    this->parent->getGraphical().clear();
    this->objs = new Objects();
    this->backgroundClock = new myclock_t;
    this->planetsBackgroundClock = new myclock_t;
    this->startTxtClock = new myclock_t;
    gettimeofday(&this->backgroundClock->start, NULL);
    gettimeofday(&this->planetsBackgroundClock->start, NULL);
    gettimeofday(&this->startTxtClock->start, NULL);
    this->startTxtToogle = false;
    this->initMenu();
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
