/*
** EPITECH PROJECT, 2020
** server.hpp
** File description:
** server
*/

#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <thread>

#define IPADDRESS "127.0.0.1"
#define UDP_PORT_SEND 13252
#define UDP_PORT_RECEIVE 13251

class myServer
{
    public:
	    myServer();
	    ~myServer();

        void handle_receive(const boost::system::error_code&, size_t, std::string);
        void handle_send(boost::shared_ptr<std::string>, const boost::system::error_code&, size_t);
        void startReceiving();

        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket socket{io_service};
        boost::asio::ip::udp::endpoint remote_endpoint;
        boost::array<char, 1024> recv_buffer;
        std::string result = "";
};

#endif
