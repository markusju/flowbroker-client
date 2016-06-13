//
// Created by Markus Jungbluth on 13.06.16.
//

#include "AbstractFlowRouteAction.h"



string AbstractFlowRouteAction::joinSet(set<string> setValue) const {
    string out = "";
    for(auto el : setValue) {
        out += el + " ";
    }
    return out;
}


string AbstractFlowRouteAction::toString() const {
    return this->getMethod() + " " + joinSet(this->getMethodArguments());
}

set<string> AbstractFlowRouteAction::getMethodArguments() const {
    return this->methodArguments;
}
