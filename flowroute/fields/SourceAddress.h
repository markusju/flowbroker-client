//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_SOURCEADDRESS_H
#define BROKER_PROTOCOL_CLIENT_SOURCEADDRESS_H


#include "AbstractAddress.h"

class SourceAddress : public AbstractAddress {

public:
    SourceAddress(const string &ipv4cidr) : AbstractAddress(ipv4cidr) { }
    string getKey() const;
};


#endif //BROKER_PROTOCOL_CLIENT_SOURCEADDRESS_H
