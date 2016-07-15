//
// Created by Markus Jungbluth on 09.06.16.
//

#include <iostream>
#include <netdb.h>
#include <vector>
#include "Client.h"
#include "exceptions/ClientErrorException.h"
#include <cstring>
#include <unistd.h>

using namespace std;

void Client::conn(string address, int port) {
//create socket if it is not already created
    if(sock == -1)
    {
        //Create socket
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            throw ClientErrorException("Could not ccreate socket.");
        }

    }
    else    {   /* OK , nothing */  }

    //setup address structure
    if(inet_addr(address.c_str()) == -1)
    {
        struct hostent *he;
        struct in_addr **addr_list;

        //resolve the hostname, its not an ip address
        if ( (he = gethostbyname( address.c_str() ) ) == NULL)
        {
            //gethostbyname failed
            throw ClientErrorException("Could not resolve hostname.");
        }

        //Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
        addr_list = (struct in_addr **) he->h_addr_list;

        for(int i = 0; addr_list[i] != NULL; i++)
        {
            //strcpy(ip , inet_ntoa(*addr_list[i]) );
            server.sin_addr = *addr_list[i];

            //cout<<address<<" resolved to "<<inet_ntoa(*addr_list[i])<<endl;

            break;
        }
    }

        //plain ip address
    else
    {
        server.sin_addr.s_addr = inet_addr( address.c_str() );
    }

    server.sin_family = AF_INET;
    server.sin_port = htons( port );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        throw ClientErrorException("Could not connect to server.");
    }
}

Client::Client() {
    sock = -1;
    port = 0;
    address = "";
}

void Client::send_data(string data) {
    //Send some data
    if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
    {
        throw ClientErrorException("Could not send data.");
    }
    
}

string Client::receive(int size) {
    vector<char> buffer(size);

    //Receive a reply from the server
    if( recv(sock , buffer.data() , buffer.size() -1 , 0) < 0)
    {
        throw ClientErrorException("Could not receive data.");
    }

    string reply(buffer.data());
    return reply;
}

Client::~Client() {
    this->disconn();
}

void Client::disconn() {
    close(this->sock);
}
