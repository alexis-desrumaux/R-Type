/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** main
*/

#include "../include/Core/Core.hpp"

int main(int argc, char **argv)
{
    std::shared_ptr<Core> core = std::make_shared<Core>();
    core->launch();
}