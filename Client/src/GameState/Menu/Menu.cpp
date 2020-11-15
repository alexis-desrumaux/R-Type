/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Menu
*/

#include "../../../include/Core/GameState/Menu/Menu.hpp"
#include <iostream>
#include <memory>

//------------------------------------Start--------------------------------
void StartBehavior::startAnimation()
{
    if (myclock::getElapsedTime_millisec(this->startTxtClock) < 1000)
        return;
    this->startTxtToogle = !this->startTxtToogle;
    this->startTxt->display = this->startTxtToogle;
    myclock::resetClock(this->startTxtClock);
}

void StartBehavior::run(std::shared_ptr<eventType_t> event)
{
    this->startAnimation();
}

void StartBehavior::initStart()
{
    std::vector<std::shared_ptr<Components>> startComponents;
    this->startTxt = std::make_shared<Component::Text>("menu_startTxt", "START", "../Client/media/Fonts/arcade.ttf", 60, Component::Color::White, std::pair<float, float>(800, 500));
    startComponents.push_back(this->startTxt);
    this->parent->setGraphical(startComponents);
}

StartBehavior::StartBehavior(Object *parent) : Behavior("StartBehavior", parent)
{
    this->parent->getGraphical().clear();
    this->startTxtClock = myclock::createClock();
    this->startTxtToogle = false;
    this->initStart();
}

StartBehavior::~StartBehavior()
{
    std::cout << "DELETED STARTBEHAVIOR" << std::endl;
}

Start::Start(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = std::make_shared<StartBehavior>(this);
}

Start::~Start()
{
    std::cout << "DELETED START" << std::endl;
}

//------------------------------------Planets--------------------------------

void PlanetsBehavior::movePlanets()
{
    std::pair<float, float> planetPos;


    if (myclock::getElapsedTime_millisec(this->planetsBackgroundClock) < 1)
        return;
    if (this->planets.empty())
        return;
    
    for (size_t i = 0; i != this->planets.size(); i += 1) {
        planetPos = this->planets.at(i)->getPosition();
        planetPos.first -= 2;
        this->planets.at(i)->setPosition(planetPos);
    }
    if (!this->enableFasterSpeed) {
        std::shared_ptr<Component::Sprite> lastplanet = this->planets.at(this->planets.size() - 1);
        std::pair<float, float> posLastPlanet = lastplanet->getPosition();
        if (posLastPlanet.first < -1180) {
            std::shared_ptr<Object> background = this->parent->getParent()->getObjectByName("background");
            if (background != NULL) {
                if (background->getBehavior()->getName() == "BackgroundBehavior") {
                    std::shared_ptr<BackgroundBehavior> bb = std::dynamic_pointer_cast<BackgroundBehavior>(background->getBehavior());
                    bb->enableFasterSpeed();
                    this->enableFasterSpeed = true;
                }
            }
        }

    }
    myclock::resetClock(this->planetsBackgroundClock);
}

void PlanetsBehavior::run(std::shared_ptr<eventType_t> event)
{
    this->movePlanets();
}

void PlanetsBehavior::initPlanets()
{
    std::vector<std::shared_ptr<Components>> graphical;
    std::shared_ptr<Component::Sprite> planet = NULL;

    planet = std::make_shared<Component::Sprite>("menu_earth", "../Client/media/Planets/Solar_System/earth.png", std::pair<float, float>(1920, 400), std::pair<float, float>(0.5, 0.5));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = std::make_shared<Component::Sprite>("menu_mars", "../Client/media/Planets/Solar_System/mars.png", std::pair<float, float>(4340, 300), std::pair<float, float>(0.3, 0.3));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = std::make_shared<Component::Sprite>("menu_jupiter", "../Client/media/Planets/Solar_System/jupiter.png", std::pair<float, float>(6860, -300), std::pair<float, float>(3, 3));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = std::make_shared<Component::Sprite>("menu_saturn", "../Client/media/Planets/Solar_System/saturn.png", std::pair<float, float>(15180, -200), std::pair<float, float>(2, 2));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = std::make_shared<Component::Sprite>("menu_uranus", "../Client/media/Planets/Solar_System/uranus.png", std::pair<float, float>(20180, 0), std::pair<float, float>(1, 1));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = std::make_shared<Component::Sprite>("menu_neptune", "../Client/media/Planets/Solar_System/neptune.png", std::pair<float, float>(23180, 0), std::pair<float, float>(1, 1));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    this->parent->setGraphical(graphical);
}

PlanetsBehavior::PlanetsBehavior(Object *parent) : Behavior("PlanetsBehavior", parent)
{
    this->parent->getGraphical().clear();
    this->planetsBackgroundClock = myclock::createClock();
    this->enableFasterSpeed = false;
    this->initPlanets();
}

PlanetsBehavior::~PlanetsBehavior()
{
    std::cout << "DELETED PLANETSBEHAVIOR" << std::endl;
}

Planets::Planets(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = std::make_shared<PlanetsBehavior>(this);
}

Planets::~Planets()
{
    std::cout << "DELETED PLANETS" << std::endl;
}

//------------------------------------Background--------------------------------


void BackgroundBehavior::enableFasterSpeed()
{
    this->enableFasterSpeedToogle = true;
}

void BackgroundBehavior::moveBackground_next()
{
    std::pair<float, float> backgroundSpritePos = this->background1->getPosition();
    std::pair<float, float> backgroundSpritePos2 = this->background2->getPosition();
    std::pair<float, float> backgroundSpritePos3 = this->background3->getPosition();

    if (backgroundSpritePos2.first <= 0) {
        backgroundSpritePos.first = 0;
        backgroundSpritePos2.first = 1920;
        backgroundSpritePos3.first = 3840;
    }
    backgroundSpritePos.first -= this->speed;
    backgroundSpritePos2.first -= this->speed;
    backgroundSpritePos3.first -= this->speed;
    background1->setPosition(backgroundSpritePos);
    background2->setPosition(backgroundSpritePos2);
    background3->setPosition(backgroundSpritePos2);
}

void BackgroundBehavior::moveBackground()
{
    if (myclock::getElapsedTime_millisec(this->backgroundClock) < 1)
        return;
    if (this->enableFasterSpeedToogle && this->speed != 20) {
        if (myclock::getElapsedTime_millisec(this->speedClock) > 100) {
            this->speed += 1;
            myclock::resetClock(this->speedClock);
        }
    }
    this->moveBackground_next();
    myclock::resetClock(this->backgroundClock);
}

void BackgroundBehavior::run(std::shared_ptr<eventType_t> event)
{
    this->moveBackground();
}

void BackgroundBehavior::initBackground()
{
    std::vector<std::shared_ptr<Components>> graphical;

    this->background1 = std::make_shared<Component::Sprite>("menu_background1", "../Client/media/Menu/menu_background1.jpg", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1));
    this->background2 = std::make_shared<Component::Sprite>("menu_background2", "../Client/media/Menu/menu_background1.jpg", std::pair<float, float>(1920, 0), std::pair<float, float>(1, 1));
    this->background3 = std::make_shared<Component::Sprite>("menu_background3", "../Client/media/Menu/menu_background1.jpg", std::pair<float, float>(3840, 0), std::pair<float, float>(1, 1));

    graphical.push_back(this->background1);
    graphical.push_back(this->background2);
    graphical.push_back(this->background3);
    this->parent->setGraphical(graphical);
}

BackgroundBehavior::BackgroundBehavior(Object *parent) : Behavior("BackgroundBehavior", parent)
{
    this->parent->getGraphical().clear();
    this->backgroundClock = myclock::createClock();
    this->speedClock = myclock::createClock();
    this->speed = 1;
    this->enableFasterSpeedToogle = false;
    this->initBackground();
}

BackgroundBehavior::~BackgroundBehavior()
{
    std::cout << "DELETED BACKGROUNDBEHAVIOR" << std::endl;
}

Background::Background(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = std::make_shared<BackgroundBehavior>(this);
}

Background::~Background()
{
    std::cout << "DELETED BACKGROUND" << std::endl;
}


//------------------------------------Menu---------------------------------------

void MenuBehavior::run(std::shared_ptr<eventType_t> event)
{
    if (event->isMouseBtnPressed == true)
        std::cout << "WOW ! Pressed at x: " << event->mouseButtonPressedCoordinates.x << " and y: " << event->mouseButtonPressedCoordinates.y << std::endl;

    for (size_t i = 0; i != this->objs->grabObjects().size(); i += 1) {
        this->objs->grabObjects().at(i)->run(event);
    }
    this->parent->setGraphical(this->objs->getGraphicalComponents());
}

void MenuBehavior::initShips()
{
    Objects *objs_ptr = this->objs.get();
    std::shared_ptr<Object> redShip = std::make_shared<Object>("redShip", objs_ptr);
    std::vector<std::shared_ptr<Components>> redShipComponents;
    redShipComponents.push_back(std::make_shared<Component::Sprite>("menu_redShip", "../Client/media/ship.png", std::pair<float, float>(500, 500), std::pair<float, float>(0.7, 0.7)));
    redShip->setGraphical(redShipComponents);

    std::shared_ptr<Object> yellowShip = std::make_shared<Object>("yellowShip", objs_ptr);
    std::vector<std::shared_ptr<Components>> yellowShipComponents;
    yellowShipComponents.push_back(std::make_shared<Component::Sprite>("menu_yellowShip", "../Client/media/ship2.png", std::pair<float, float>(100, 500), std::pair<float, float>(0.7, 0.7)));
    yellowShip->setGraphical(yellowShipComponents);

    std::shared_ptr<Object> greenShip = std::make_shared<Object>("greenShip", objs_ptr);
    std::vector<std::shared_ptr<Components>> greenShipComponents;
    greenShipComponents.push_back(std::make_shared<Component::Sprite>("menu_greenShip", "../Client/media/ship3.png", std::pair<float, float>(250, 300), std::pair<float, float>(0.7, 0.7)));
    greenShip->setGraphical(greenShipComponents);

    std::shared_ptr<Object> blueShip = std::make_shared<Object>("blueShip", objs_ptr);
    std::vector<std::shared_ptr<Components>> blueShipComponents;
    blueShipComponents.push_back(std::make_shared<Component::Sprite>("menu_blueShip", "../Client/media/ship4.png", std::pair<float, float>(250, 700), std::pair<float, float>(0.7, 0.7)));
    blueShip->setGraphical(blueShipComponents);

    this->objs->grabObjects().push_back(redShip);
    this->objs->grabObjects().push_back(yellowShip);
    this->objs->grabObjects().push_back(greenShip);
    this->objs->grabObjects().push_back(blueShip);
}

void MenuBehavior::initMenu()
{
    Objects *objs_ptr = this->objs.get();
    std::shared_ptr<Object> audio = std::make_shared<Object>("audio", objs_ptr);
    std::vector<std::shared_ptr<Components>> audioComponents;
    audioComponents.push_back(std::make_shared<Component::Audio>("audio", "../Client/media/main.ogg", Component::AudioState::PLAY, true));
    audio->setGraphical(audioComponents);

    std::shared_ptr<Object> background = std::make_shared<Background>("background", objs_ptr);
    std::shared_ptr<Object> planets = std::make_shared<Planets>("planets", objs_ptr);

    std::shared_ptr<Object> title = std::make_shared<Object>("title", objs_ptr);
    std::vector<std::shared_ptr<Components>> titleComponents;
    titleComponents.push_back(std::make_shared<Component::Sprite>("menu_title1", "../Client/media/Menu/title1.png", std::pair<float, float>(700, 50), std::pair<float, float>(1.3, 1.3)));
    title->setGraphical(titleComponents);

    std::shared_ptr<Object> start = std::make_shared<Start>("start", objs_ptr);

    this->objs->grabObjects().push_back(audio);
    this->objs->grabObjects().push_back(background);
    this->objs->grabObjects().push_back(planets);
    this->objs->grabObjects().push_back(title);
    this->initShips();
    this->objs->grabObjects().push_back(start);
}

MenuBehavior::MenuBehavior(Object *parent) : Behavior("MenuBehavior", parent)
{
    this->parent->getGraphical().clear();
    this->objs = std::make_shared<Objects>(this->parent);
    this->initMenu();
}

MenuBehavior::~MenuBehavior()
{
    std::cout << "DELETED MENUBEHAVIOR" << std::endl;
}

Menu::Menu(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = std::make_shared<MenuBehavior>(this);
}

Menu::~Menu()
{
    std::cout << "DELETED MENU" << std::endl;
}