//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERPROTOCOL_H
#define BROKER_PROTOCOL_CLIENT_BROKERPROTOCOL_H


#include "../client/BrokerClient.h"
#include "BrokerReply.h"
#include "BrokerRequest.h"
#include "parser/BrokerReplyParser.h"
#include "evaluator/BrokerReplyEvaluator.h"

class BrokerProtocol {
public:
    BrokerProtocol(BrokerClient* brokerClient, BrokerReplyParser* brokerReplyParser, BrokerReplyEvaluator* brokerReplyEvaluator);
    void send(BrokerRequest* request);
private:
    BrokerClient* brokerClient;
    BrokerReplyParser* brokerReplyParser;
    BrokerReplyEvaluator* brokerReplyEvaluator;

};


#endif //BROKER_PROTOCOL_CLIENT_BROKERPROTOCOL_H
