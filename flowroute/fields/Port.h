//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PORT_H
#define BROKER_PROTOCOL_CLIENT_PORT_H


#include "types/AbstractFlowRouteField.h"

class Port : public AbstractFlowRouteField {


public:
    string getKey() const;
    Port(string value);
};


#endif //BROKER_PROTOCOL_CLIENT_PORT_H
