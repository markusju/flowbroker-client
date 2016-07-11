//
// Created by Markus Jungbluth on 10.06.16.
//

#include "Protocol.h"
#include <algorithm>
#include "../exceptions/FlowRouteException.h"


string Protocol::getKey() const {
    return "Protocol";
}

Protocol::Protocol(string value) : AbstractSetOfThings(value) {
    this->checkValue();
}

set<string> Protocol::getThings() {
    return {"tcp", "udp"};
}
