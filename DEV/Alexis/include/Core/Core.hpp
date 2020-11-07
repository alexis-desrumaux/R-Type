/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <string.h>

#include "../../lib/GameCore/include/Objects/Objects.hpp"
#include "../../lib/graphical/sfml/include/IGLib.hpp"
#include "../../lib/graphical/sfml/include/Components.hpp"

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
    //data
        IGLib *gl;
        void *handle_lib;
        Objects *gameObjs;
        std::string keyPressed;
};

#endif /* !CORE_HPP_ */
