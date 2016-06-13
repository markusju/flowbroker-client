//
// Created by Markus Jungbluth on 10.06.16.
//

#include "Protocol.h"

Protocol::Protocol(set<string> setValue) : AbstractFlowRouteField(setValue) {
    if (std::includes(setValue.begin(), setValue.end(),
                      this->allowedProt.begin(), this->allowedProt.end())) {
        return;
    }

    throw "Noo";
}



string Protocol::getKey() const {
    return "Protocol";
}

Protocol::Protocol(string value) : AbstractFlowRouteField(value) { }
