//
// Created by Markus Jungbluth on 11.07.16.
//

#include "PacketLength.h"

PacketLength::PacketLength(string value) : AbstractFlowRouteField(value) {
    packetLengthExpression.analyze(setValue);
}

string PacketLength::getKey() const {
    return "Packet-Length";
}
