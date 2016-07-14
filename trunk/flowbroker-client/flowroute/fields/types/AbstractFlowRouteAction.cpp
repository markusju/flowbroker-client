//
// Created by Markus Jungbluth on 13.06.16.
//

#include "AbstractFlowRouteAction.h"
#include "../../../helper/stringHelper.h"





string AbstractFlowRouteAction::toString() const {
    return this->getMethod() + " " + stringHelper::joinVector(this->getMethodArguments());
}

vector<string> AbstractFlowRouteAction::getMethodArguments() const {
    return this->methodArguments;
}
