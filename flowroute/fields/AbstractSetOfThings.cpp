//
// Created by Markus Jungbluth on 11.07.16.
//



#include "AbstractSetOfThings.h"
#include "../exceptions/FlowRouteException.h"

void AbstractSetOfThings::checkValue() {
    if (std::includes(this->getThings().begin(), this->getThings().end(),
                      setValue.begin(), setValue.end())) {
        return;
    }

    throw FlowRouteException("Invalid values for FlowRoute Protocol parameter!");

}

AbstractSetOfThings::AbstractSetOfThings(string value) : AbstractFlowRouteField(value) {}
