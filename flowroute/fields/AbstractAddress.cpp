//
// Created by Markus Jungbluth on 10.06.16.
//

#include "AbstractAddress.h"


AbstractAddress::AbstractAddress(string value) : AbstractFlowRouteField(value) {
    if (!regex_match(value, *this->reg)) {
        throw "Not an IPv4 CIDR!";
    }
}

