//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSEERROREXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSEERROREXCEPTION_H

#include <stdexcept>

using namespace std;

class BrokerReplyParseErrorException : public runtime_error {
public:
    BrokerReplyParseErrorException(const char *msg) : runtime_error(msg) {}
    BrokerReplyParseErrorException(string& msg) : runtime_error(msg) {}
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSEERROREXCEPTION_H
