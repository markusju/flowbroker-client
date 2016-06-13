//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_FLOWROUTEEXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_FLOWROUTEEXCEPTION_H

#include <exception>
#include <stdexcept>


using namespace std;

class FlowRouteException : public runtime_error{

public:
    FlowRouteException(const char *msg) : runtime_error(msg) {}
    FlowRouteException(string& msg) : runtime_error(msg) {}
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTEEXCEPTION_H
