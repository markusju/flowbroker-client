//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_SOURCEPORT_H
#define BROKER_PROTOCOL_CLIENT_SOURCEPORT_H


#include "AbstractPort.h"

using namespace std;

class SourcePort : public AbstractPort {


public:
    string getKey() const;
    SourcePort(string value) : AbstractPort(value) { }
};


#endif //BROKER_PROTOCOL_CLIENT_SOURCEPORT_H
