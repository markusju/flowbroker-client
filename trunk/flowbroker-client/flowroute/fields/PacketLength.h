//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PACKETLENGTH_H
#define BROKER_PROTOCOL_CLIENT_PACKETLENGTH_H


#include "types/AbstractFlowRouteField.h"

class PacketLength : AbstractFlowRouteField {
    PacketLength(string input);
};


#endif //BROKER_PROTOCOL_CLIENT_PACKETLENGTH_H
