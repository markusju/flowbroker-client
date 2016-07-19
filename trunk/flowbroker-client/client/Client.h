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


class Client {

private:
    int sock;
    string address;
    int port;
    struct sockaddr_in server;

public:
    Client();
    virtual ~Client();
    void conn(string address, int port);
    void disconn();
    void send_data(string data);
    string receive(int size);
};


#endif //BROKER_PROTOCOL_CLIENT_CLIENT_H