//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H

#include <string>
#include <vector>
#include "../BrokerReply.h"

using namespace std;

class BrokerReplyParser {
public:
    BrokerReplyParser();
    /**
     * Evaluates a string containing the reply from the Broker Server
     * @param input String containing the reply message
     * @return A BrokerReply object
     */
    BrokerReply evaluate(string input);
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H
