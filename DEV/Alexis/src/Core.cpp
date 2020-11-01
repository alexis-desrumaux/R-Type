/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Core
*/

#include "../include/Core/Core.hpp"

void resetListUpdateComponent(std::vector<Components *> update)
{
    update.clear();
}

void resetStateComponents(std::vector<Components *> components)
{
    if (components.empty() != true) {
        for (size_t i = 0; i != components.size(); i += 1) {
            components.at(i)->resetState();
        }
    }
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

int Core::launch()
{
    this->components.push_back(new Component::Audio("audio", "./media/space1.ogg", Component::AudioState::PLAY, true));
    this->components.push_back(new Component::Sprite("Background", "./media/background.jpg", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->components.push_back(new Component::Sprite("Ship", "./media/ship.png", std::pair<float, float>(100, 330), std::pair<float, float>(0.7, 0.7), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->gl->initLib(this->components);

    while (this->gl->isRunning == true) {
        this->keyPressed = this->gl->display(this->update);
        if (!this->keyPressed.empty()) {
            std::cout << this->keyPressed << std::endl;
        }
        resetStateComponents(this->components);
        resetListUpdateComponent(this->update);
    }
    return 0;
}

Core::Core()
{
    this->handle_lib = load("./lib/graphical/lib_sfml.so");
    this->gl = getGLib("createLib", this->handle_lib);
    this->gl->isRunning = true;
}

Core::~Core()
{
}
