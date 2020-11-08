/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Menu
*/

#include "../../../include/Core/GameState/Menu/Menu.hpp"

//------------------------------------Start--------------------------------
void StartBehavior::startAnimation()
{
    if (myclock::getElapsedTime_millisec(this->startTxtClock) < 1000)
        return;
    this->startTxtToogle = !this->startTxtToogle;
    this->startTxt->display = this->startTxtToogle;
    this->startTxt->setState(Component::State::UPDATE);
    myclock::resetClock(this->startTxtClock);
}

void StartBehavior::run(std::string &keyPressed)
{
    this->startAnimation();
}

void StartBehavior::initStart()
{
    std::vector<Components *> startComponents;
    this->startTxt = new Component::Text("menu_startTxt", "START", "./media/Fonts/arcade.ttf", 60, Component::Color::White, std::pair<float, float>(800, 500), std::pair<int, int>(-1, -1));
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

}

Start::Start(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = new StartBehavior(this);
}

Start::~Start()
{

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
        this->planets.at(i)->setState(Component::State::UPDATE);
    }
    if (!this->enableFasterSpeed) {
        Component::Sprite *lastplanet = this->planets.at(this->planets.size() - 1);
        std::pair<float, float> posLastPlanet = lastplanet->getPosition();
        if (posLastPlanet.first < -1180) {
            Object *background = this->parent->parent->getObjectByName("background");
            if (background != NULL) {
                if (background->getBehavior()->getName() == "BackgroundBehavior") {
                    BackgroundBehavior *bb = dynamic_cast<BackgroundBehavior *>(background->getBehavior());
                    bb->enableFasterSpeed();
                    this->enableFasterSpeed = true;
                }
            }
        }

    }
    myclock::resetClock(this->planetsBackgroundClock);
}

void PlanetsBehavior::run(std::string &key)
{
    this->movePlanets();
}

void PlanetsBehavior::initPlanets()
{
    std::vector<Components *> graphical;
    Component::Sprite *planet = NULL;

    planet = new Component::Sprite("menu_earth", "./media/Menu/earth.png", std::pair<float, float>(1920, 400), std::pair<float, float>(0.5, 0.5), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = new Component::Sprite("menu_mars", "./media/Menu/mars.png", std::pair<float, float>(4340, 300), std::pair<float, float>(0.3, 0.3), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = new Component::Sprite("menu_jupiter", "./media/Menu/jupiter.png", std::pair<float, float>(6860, -300), std::pair<float, float>(3, 3), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = new Component::Sprite("menu_saturn", "./media/Menu/saturn.png", std::pair<float, float>(15180, -200), std::pair<float, float>(2, 2), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = new Component::Sprite("menu_uranus", "./media/Menu/uranus.png", std::pair<float, float>(20180, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->planets.push_back(planet);
    graphical.push_back(planet);
    planet = new Component::Sprite("menu_neptune", "./media/Menu/neptune.png", std::pair<float, float>(23180, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
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

}

Planets::Planets(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = new PlanetsBehavior(this);
}

Planets::~Planets()
{

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
    background1->setState(Component::State::UPDATE);
    background2->setState(Component::State::UPDATE);
    background3->setState(Component::State::UPDATE);
}

void BackgroundBehavior::moveBackground()
{
    if (myclock::getElapsedTime_millisec(this->backgroundClock) < 1)
        return;
    if (this->enableFasterSpeedToogle && this->speed != 10) {
        if (myclock::getElapsedTime_millisec(this->speedClock) > 500) {
            this->speed += 1;
            myclock::resetClock(this->speedClock);
        }
    }
    this->moveBackground_next();
    myclock::resetClock(this->backgroundClock);
}

void BackgroundBehavior::run(std::string &key)
{
    this->moveBackground();
}

void BackgroundBehavior::initBackground()
{
    std::vector<Components *> graphical;

    this->background1 = new Component::Sprite("menu_background1", "./media/Menu/menu_background1.jpg", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->background2 = new Component::Sprite("menu_background2", "./media/Menu/menu_background1.jpg", std::pair<float, float>(1920, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->background3 = new Component::Sprite("menu_background3", "./media/Menu/menu_background1.jpg", std::pair<float, float>(3840, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));

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

}

Background::Background(std::string name, Objects *parent) : Object(name, parent)
{
    this->behavior = new BackgroundBehavior(this);
}

Background::~Background()
{

}


//------------------------------------Menu---------------------------------------

void MenuBehavior::run(std::string &key)
{
    for (size_t i = 0; i != this->objs->grabObjects().size(); i += 1)
        this->objs->grabObjects().at(i)->run(key);
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

    Object *background = new Background("background", this->objs);
    Object *planets = new Planets("planets", this->objs);

    Object *title = new Object("title", this->objs);
    std::vector<Components *> titleComponents;
    titleComponents.push_back(new Component::Sprite("menu_title1", "./media/Menu/title1.png", std::pair<float, float>(700, 50), std::pair<float, float>(1.3, 1.3), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    title->setGraphical(titleComponents);

    Object *start = new Start("start", this->objs);

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
    this->objs = new Objects();
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
