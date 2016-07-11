//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PACKETLENGTH_H
#define BROKER_PROTOCOL_CLIENT_PACKETLENGTH_H


#include "types/AbstractFlowRouteField.h"
#include "expressions/PacketLengthExpression.h"

class PacketLength : public AbstractFlowRouteField {

public:
    PacketLength(string value);
    string getKey() const;
private:
    PacketLengthExpression packetLengthExpression;

};


#endif //BROKER_PROTOCOL_CLIENT_PACKETLENGTH_H
