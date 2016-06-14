//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERPROTOCOL_H
#define BROKER_PROTOCOL_CLIENT_BROKERPROTOCOL_H


#include "../client/BrokerClient.h"
#include "BrokerReply.h"
#include "BrokerRequest.h"

class BrokerProtocol {
public:
    BrokerProtocol(BrokerClient* brokerClient);
    BrokerReply send(BrokerRequest* request);
private:
    BrokerClient* brokerClient;

};


#endif //BROKER_PROTOCOL_CLIENT_BROKERPROTOCOL_H
