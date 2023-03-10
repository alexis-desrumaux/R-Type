/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <time.h>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <string.h>

#include "../../lib/GameCore/include/Objects/Objects.hpp"
#include "../../lib/graphical/sfml/include/IGLib.hpp"
#include "../../lib/graphical/sfml/include/SFML.hpp"
#include "../../lib/graphical/sfml/include/Components.hpp"
#include "../../lib/graphical/sfml/include/Event.hpp"

#include "./GameState/Menu/Menu.hpp"

namespace Game
{
    enum State
    {
        MENU,
    };
}

class Core {
    public:
    //functions
        Core();
        ~Core();
        int launch();
    //data
    protected:
    private:
    //functions
        void runGame();
        void runMenu();
        void initMenu();
    //data
        std::shared_ptr<IGLib> gl;
        std::shared_ptr<void> handle_lib;
        std::shared_ptr<Objects> gameObjs;
        std::shared_ptr<eventType_t> event;
        Game::State state;
        bool GameStateInit;
};

#endif /* !CORE_HPP_ */
