/*
** EPITECH PROJECT, 2020
** server.cpp
** File description:
** server
*/

#include "../include/server.hpp"

myServer::myServer() {
    socket.open(boost::asio::ip::udp::v4());
    socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(IPADDRESS), UDP_PORT_RECEIVE));
    wait();
}

myServer::~myServer() {

}

void myServer::send(std::string input) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    this->sender(input);
}

void myServer::handle_receive(const boost::system::error_code& error, size_t bytes_transferred) {
    if (error) {
        std::cout << "Receive failed: " << error.message() << "\n";
        return;
    }
    this->result = std::string(recv_buffer.begin(), recv_buffer.begin()+bytes_transferred);
    std::cout << "Received: '" << this->result << "' (" << error.message() << ")\n";
}

void myServer::wait() {
    socket.async_receive_from(boost::asio::buffer(recv_buffer),
        remote_endpoint,
        boost::bind(&myServer::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void myServer::receiver()
{
    std::cout << "Receiving\n";
    io_service.run();
    std::cout << "Receiver exit\n";
}

void myServer::sender(std::string in) {
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket socket(io_service);
    boost::asio::ip::udp::endpoint remote_endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(IPADDRESS), UDP_PORT_SEND);
    socket.open(boost::asio::ip::udp::v4());

    boost::system::error_code err;
    auto sent = socket.send_to(boost::asio::buffer(in), remote_endpoint, 0, err);
    socket.close();
    std::cout << "Sent Payload --- " << sent << "\n";
}
