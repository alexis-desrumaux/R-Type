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

    server.io_service.run(); //Cette partie fait une boucle qui recoit constamment les donnees des clients

    //server.handle_receive(boost::asio::placeholders::error,
    //boost::asio::placeholders::bytes_transferred, "Un jour");
	return 0;
}
