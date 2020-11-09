/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main
*/

#include "../include/server.hpp"

int main(int ac, char **av)
{
    myServer server;

    server.receiver(); //Le resultat est stocker dans server.result
    server.send("Hello From Server");
	return 0;
}
