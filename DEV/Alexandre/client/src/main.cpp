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

    client.send("Hello From Client");
    client.receiver(); //Le resultat est stocker dans client.result
	return 0;
}
