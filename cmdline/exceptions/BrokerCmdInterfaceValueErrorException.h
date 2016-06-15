//
// Created by Markus Jungbluth on 15.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACEVALUEERROREXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACEVALUEERROREXCEPTION_H

#include <stdexcept>

using namespace std;

class BrokerCmdInterfaceValueErrorException : public runtime_error {
public:
    BrokerCmdInterfaceValueErrorException(const char *msg) : runtime_error(msg) {}
    BrokerCmdInterfaceValueErrorException(string& msg) : runtime_error(msg) {}
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACEVALUEERROREXCEPTION_H
