//
// Created by Markus Jungbluth on 10.06.16.
//

#include "AbstractAddress.h"
#include "../exceptions/FlowRouteException.h"


AbstractAddress::AbstractAddress(string value) : AbstractFlowRouteField(value) {
    if (!regex_match(value, *this->reg)) {
        throw FlowRouteException("Not an IPv4 CIDR");
    }
}

