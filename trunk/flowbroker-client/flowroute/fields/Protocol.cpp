//
// Created by Markus Jungbluth on 10.06.16.
//

#include "Protocol.h"
#include "../exceptions/FlowRouteException.h"

Protocol::Protocol(set<string> setValue) : AbstractFlowRouteField(setValue) {
    if (std::includes(this->allowedProt.begin(), this->allowedProt.end(),
                      setValue.begin(), setValue.end())) {
        return;
    }

    throw FlowRouteException("Invalid values for this parameter!");
}



string Protocol::getKey() const {
    return "Protocol";
}

Protocol::Protocol(string value) : AbstractFlowRouteField(value) { }
