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

#include "../graphical/SFML/IGLib.hpp"
#include "../graphical/SFML/Components.hpp"

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
        std::vector<Components *> components;
        std::vector<Components *> update;
        std::string keyPressed;
};

#endif /* !CORE_HPP_ */
