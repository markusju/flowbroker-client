//
// Created by Markus Jungbluth on 10.06.16.
//

#include "Protocol.h"
#include <algorithm>
#include "../exceptions/FlowRouteException.h"

Protocol::Protocol(set<string> setValue) : AbstractFlowRouteField(setValue) {
    if (std::includes(this->allowedProt.begin(), this->allowedProt.end(),
                      setValue.begin(), setValue.end())) {
        return;
    }

    throw FlowRouteException("Invalid values for FlowRoute Protocol parameter!");
}



string Protocol::getKey() const {
    return "Protocol";
}

Protocol::Protocol(string value) : AbstractFlowRouteField(value) {}
