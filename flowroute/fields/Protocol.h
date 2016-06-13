//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PROTOCOL_H
#define BROKER_PROTOCOL_CLIENT_PROTOCOL_H


#include "types/AbstractFlowRouteField.h"
#include <string>

class Protocol : public AbstractFlowRouteField {

    const vector<string> allowedProt = {"tcp", "udp"};

public:
    string getKey() const;
    Protocol(set<string> setValue);
    Protocol(string value);

};


#endif //BROKER_PROTOCOL_CLIENT_PROTOCOL_H
