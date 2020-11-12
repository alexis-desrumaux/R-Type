/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main
*/

#include "../include/client.hpp"

int main(int ac, char **av)
{
    myClient client;

    client.io_service.run(); //    Si run est executer ici seulement les handlers appeler avant lui sont executer

    client.call("Cool");
    client.call("Michel !");
    std::cout << "MIAOU = " << client.count << std::endl;
	return 0;
}
