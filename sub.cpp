#include <iostream>

#include "zmq.hpp"
#include "zmq_addon.hpp"

std::string s_recv (zmq::socket_t & socket, int flags = 0) {

    zmq::message_t message;
    socket.recv(&message, flags);

    return std::string(static_cast<char*>(message.data()), message.size());
}

int main () {
    //  Prepare our context and subscriber
    zmq::context_t context(1);
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5563");
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "B", 1);

    while (1) {

        //  Read envelope with address
        std::string address = s_recv (subscriber);
        //  Read message contents
        std::string contents = s_recv (subscriber);

        std::cout << "[" << address << "] " << contents << std::endl;
    }
    return 0;
}
