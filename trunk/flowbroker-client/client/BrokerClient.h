//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERCLIENT_H
#define BROKER_PROTOCOL_CLIENT_BROKERCLIENT_H


#include <string>
#include "../protocol/BrokerRequest.h"
#include "../protocol/BrokerReply.h"
#include "Client.h"

using namespace std;

class BrokerClient {
public:
    BrokerClient(string host, int port);
    string sendRequest(string request);

protected:
    void connect();
    void disconnect();
private:


    string secret;

    Client client;
    string host;
    int port;

};


#endif //BROKER_PROTOCOL_CLIENT_BROKERCLIENT_H
