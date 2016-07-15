//
// Created by Markus Jungbluth on 15.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREQUESTFAILEDEXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_BROKERREQUESTFAILEDEXCEPTION_H

#include <stdexcept>

using namespace std;

class BrokerRequestFailedException : public runtime_error {

public:
    BrokerRequestFailedException(const char *msg) : runtime_error(msg) {}
    BrokerRequestFailedException(string& msg) : runtime_error(msg) {}

};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREQUESTFAILEDEXCEPTION_H
