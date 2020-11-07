/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Core
*/

#include "../include/Core/Core.hpp"


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

int Core::launch()
{
    Object *audio = new Object("audio", this->gameObjs);
    std::vector<Components *> audioComponents;
    audioComponents.push_back(new Component::Audio("audio", "./media/space1.ogg", Component::AudioState::PLAY, true));
    audio->setGraphical(audioComponents);

    this->gameObjs->grabObjects().push_back(audio);
    while (this->gl->isRunning == true) {
        this->keyPressed = this->gl->display(this->gameObjs->getGraphicalComponents());
        if (!this->keyPressed.empty())
            std::cout << this->keyPressed << std::endl;
    }
    return 0;
}

Core::Core()
{
    this->handle_lib = load("./lib/graphical/lib_sfml.so");
    this->gl = getGLib("createLib", this->handle_lib);
    this->gl->isRunning = true;
    this->gameObjs = new Objects();
}

Core::~Core()
{
}
