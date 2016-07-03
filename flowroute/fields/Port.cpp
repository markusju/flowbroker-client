//
// Created by Markus Jungbluth on 03.07.16.
//

#include "Port.h"

string Port::getKey() const {
    return "Port";
}

Port::Port(string value) : AbstractFlowRouteField(value) {}
