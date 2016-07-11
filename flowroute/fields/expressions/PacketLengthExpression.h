//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PACKETLENGTHEXPRESSION_H
#define BROKER_PROTOCOL_CLIENT_PACKETLENGTHEXPRESSION_H


#include "NumberRange.h"
#include "PortExpression.h"

/**
 * Defines a validator for PacketLength Expressions, which are identical to PortExpressions..
 */
class PacketLengthExpression : public PortExpression {

};

#endif //BROKER_PROTOCOL_CLIENT_PACKETLENGTHEXPRESSION_H
