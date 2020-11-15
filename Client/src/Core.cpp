/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Core
*/

#include "../include/Core/Core.hpp"

void Core::runMenu()
{

}

void Core::initMenu()
{
    Objects *o = this->gameObjs.get();
    this->gameObjs->grabObjects().push_back(std::make_shared<Menu>("Menu", o));
    this->GameStateInit = true;
}

void Core::runGame()
{
    switch (this->state)
    {
    case Game::State::MENU:
        if (this->GameStateInit == false)
            this->initMenu();
        else
            this->gameObjs->getObjectByName("Menu")->run(this->event);
        break;
    default:
        break;
    }
}

int Core::launch()
{
    while (this->gl->isRunning == true) {
        this->runGame();
        this->event = this->gl->display(this->gameObjs->getGraphicalComponents());
        if (!this->event->keyPressed.empty())
            std::cout << this->event->keyPressed << std::endl;
    }
    //delete this->gl;
    //delete this->gameObjs;
    return 0;
}

IGLib *getGLib(std::string entry_point, void *_handle)
{
    IGLib *(*ptr)(void);
    ptr = reinterpret_cast<IGLib *(*)()>(dlsym(_handle, entry_point.c_str()));

    if (ptr == NULL) {
        std::cerr << "dlsym Error: " << dlerror() << std::endl;
		return (NULL);
    }
	return ptr();
}

void *load(std::string _path)
{
	void *_handle = dlopen(_path.c_str(), RTLD_NOW | RTLD_GLOBAL);

	if (_handle == NULL)
	{
        std::cerr << "dlopen Error: " << dlerror() << " in lib " << _path << std::endl;
        std::cout << "OPEN FAILED" << std::endl;
        exit(84);
	}
    return _handle;
}

Core::Core()
{
    /*this->handle_lib = load("./lib/graphical/lib_sfml.so");
    this->gl = getGLib("createLib", this->handle_lib);*/
    this->gl = std::make_shared<SFML::SFML>();
    this->gl->isRunning = true;
    this->gameObjs = std::make_shared<Objects>();
    this->GameStateInit = false;
}

Core::~Core()
{
    std::cout << "DELETED CORE" << std::endl;
}
