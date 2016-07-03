//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_DESTINATIONPORT_H
#define BROKER_PROTOCOL_CLIENT_DESTINATIONPORT_H


#include "AbstractPort.h"
#include "Port.h"

using namespace std;

class DestinationPort : public AbstractPort {


public:
    string getKey() const;
    DestinationPort(string value) : AbstractPort(value) { }
};


#endif //BROKER_PROTOCOL_CLIENT_DESTINATIONPORT_H
