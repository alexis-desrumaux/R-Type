/*
** EPITECH PROJECT, 2020
** server.cpp
** File description:
** server
*/

#include "../include/server.hpp"

myServer::myServer() {
    socket.open(boost::asio::ip::udp::v4());
    socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), UDP_PORT_RECEIVE));
    startReceiving();
}

myServer::~myServer() {

}

void myServer::startReceiving(void)
{
    socket.async_receive_from(boost::asio::buffer(recv_buffer),
        remote_endpoint,
        boost::bind(&myServer::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, "Hello From Server"));
}

void myServer::handle_receive(const boost::system::error_code& error, size_t bytes_transferred, std::string str)
{
    if (!error) {
        boost::shared_ptr<std::string> message(new std::string(str));

        socket.async_send_to(boost::asio::buffer(*message), remote_endpoint, boost::bind(&myServer::handle_send, this, message, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        this->result = std::string(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred);

        std::cout << "RECUS = " << this->result << std::endl;

        startReceiving();
    }
}

void myServer::handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "ENVOYER = " << *message << std::endl;
}
