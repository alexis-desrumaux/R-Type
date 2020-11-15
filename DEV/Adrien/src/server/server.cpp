/*
** EPITECH PROJECT, 2020
** server.cpp
** File description:
** server
*/

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "Rtype.hpp"
#include <unistd.h>

using boost::asio::ip::udp;

class Server
{
public:
    Server(boost::asio::io_service& io_service);
private:
    void start_receive();
    void handle_receive(const boost::system::error_code& error, std::size_t);
    void handle_send(boost::shared_ptr<std::string> message,
                     const boost::system::error_code& error,
                     std::size_t bytes_transferred);
    IGame *_game;
    size_t _nb_client;
    udp::socket socket_;
    udp::endpoint _endpoints;
    udp::endpoint remote_endpoint_;
    boost::array<char, 5> recv_buffer_;
    char  _id;
};

Server::Server(boost::asio::io_service& io_service) :
    socket_(io_service, udp::endpoint(udp::v4(), 1312))
{
    _game = new Rtype(1024, 720, "Th is RType.");
    _nb_client = 0;
    start_receive();
}


void Server::start_receive()
{
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), _endpoints,
        boost::bind(&Server::handle_receive, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
}

void Server::handle_receive(const boost::system::error_code& error,
                                std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size) {
        _id = recv_buffer_.data()[0];
        std::map<size_t, Object *> info = _game->getEntity();
        std::vector<size_t> all = _game->getAllEntity();
        for (size_t i = 0; i < all.size(); i++) {
            std::vector<size_t> events = info[all.at(i)]->getEvents();
            for (size_t y = 0; y < events.size(); y++) {
                if (_id != '1') {
                    if (recv_buffer_.data()[y] == 'T')
                        info[all.at(i)]->setEvent(events.at(y), true);
                    else
                        info[all.at(i)]->setEvent(events.at(y), false);
                }
            }
        }
        boost::shared_ptr<std::string> message(new std::string(_game->getMessage()));
        socket_.async_send_to(boost::asio::buffer(*message), _endpoints,
                              boost::bind(&Server::handle_send, this, message,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
        _game->updateRtype();
        start_receive();
    }
}

void Server::handle_send(boost::shared_ptr<std::string> message,
                             const boost::system::error_code& error,
                             std::size_t bytes_transferred) {}

int main()
{
    try
    {
        boost::asio::io_service io_service;
        Server server(io_service);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
