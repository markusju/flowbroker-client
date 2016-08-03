//
// Created by Markus Jungbluth on 09.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_CLIENT_H
#define BROKER_PROTOCOL_CLIENT_CLIENT_H

#include <iosfwd>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

/**
 * Simple Socket client class in C++
 * Adapted version from the original code.
 *
 * @author Silver Moon
 * @link http://www.binarytides.com/code-a-simple-socket-client-class-in-c/
 */
class Client {

private:
    int sock;
    string address;
    int port;
    struct sockaddr_in server;

public:
    Client();
    virtual ~Client();
    /**
     * Connects and creates a socket.
     * @param address IP address or hostname
     * @param port TCP Port
     */
    void conn(string address, int port);
    /**
     * Closes the socket.
     */
    void disconn();
    /**
     * Sends data to the remote station
     * @param data Data to be sent.
     */
    void send_data(string data);
    /**
     * Receives date from the client
     * @param size Buffer Size in byte (ideally powers of two)
     * @return A string containing the received data.
     */
    string receive(int size);
};


#endif //BROKER_PROTOCOL_CLIENT_CLIENT_H
