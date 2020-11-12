/*
** EPITECH PROJECT, 2020
** client.cpp
** File description:
** client
*/

#include "../include/client.hpp"

myClient::myClient() {
    socket.open(boost::asio::ip::udp::v4());
    remote_endpoint_receive = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(IPADDRESS), UDP_PORT_RECEIVE);
    remote_endpoint_send = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(IPADDRESS), UDP_PORT_SEND);
    //this->io_service.run();   //  Si run est executer ici touts les handlers semblent etre executer mais rien ne print
    send("Bonjour Du Client");
    startReceiving();
}

myClient::~myClient() {

}

void myClient::call(std::string str)
{
    send(str);
}

void myClient::send(std::string str)
{
    boost::shared_ptr<std::string> message(new std::string(str));

    socket.async_send_to(boost::asio::buffer(*message), remote_endpoint_send, boost::bind(&myClient::handle_send, this, message, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}

void myClient::startReceiving(void)
{
    socket.async_receive_from(boost::asio::buffer(recv_buffer),
        remote_endpoint_receive,
        boost::bind(&myClient::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void myClient::handle_receive(const boost::system::error_code& error, size_t bytes_transferred)
{
    if (!error) {
        this->result = std::string(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred);
        std::cout << "RECUS = " << this->result << std::endl;
        startReceiving();
    }
}

void myClient::handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "ENVOYER = " << *message << std::endl;
}
