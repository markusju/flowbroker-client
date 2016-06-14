//
// Created by Markus Jungbluth on 14.06.16.
//

#include "BrokerProtocol.h"

BrokerProtocol::BrokerProtocol(BrokerClient *brokerClient) {
    this->brokerClient = brokerClient;
}

BrokerReply BrokerProtocol::send(BrokerRequest *request) {


}
