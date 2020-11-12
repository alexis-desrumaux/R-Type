/*
** EPITECH PROJECT, 2020
** client.hpp
** File description:
** client
*/

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <thread>

#define IPADDRESS "127.0.0.1"
#define UDP_PORT_SEND 13251
#define UDP_PORT_RECEIVE 13252

class myClient
{
    public:
	    myClient();
	    ~myClient();

        void handle_receive(const boost::system::error_code&, size_t);
        void handle_send(boost::shared_ptr<std::string>, const boost::system::error_code&, size_t);
        void startReceiving();
        void send(std::string);
        void call(std::string);

        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket socket{io_service};
        boost::asio::ip::udp::endpoint remote_endpoint_receive;
        boost::asio::ip::udp::endpoint remote_endpoint_send;
        boost::array<char, 1024> recv_buffer;
        std::string result = "";
        int count = 0;
};

#endif
