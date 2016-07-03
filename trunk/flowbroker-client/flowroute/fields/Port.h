//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PORT_H
#define BROKER_PROTOCOL_CLIENT_PORT_H


#include "types/AbstractFlowRouteField.h"
#include "AbstractPort.h"

class Port : public AbstractPort {


public:
    string getKey() const;
    Port(string value) : AbstractPort(value) { }
};


#endif //BROKER_PROTOCOL_CLIENT_PORT_H
