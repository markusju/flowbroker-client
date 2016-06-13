//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_DESTINATIONADDRESS_H
#define BROKER_PROTOCOL_CLIENT_DESTINATIONADDRESS_H


#include "AbstractAddress.h"

class DestinationAddress : public AbstractAddress {

public:
    DestinationAddress(string ipv4cidr) : AbstractAddress(ipv4cidr) { }
    string getKey() const;
};


#endif //BROKER_PROTOCOL_CLIENT_DESTINATIONADDRESS_H
