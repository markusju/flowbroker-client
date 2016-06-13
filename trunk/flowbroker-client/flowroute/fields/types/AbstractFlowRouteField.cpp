//
// Created by Markus Jungbluth on 10.06.16.
//

#include "AbstractFlowRouteField.h"

string AbstractFlowRouteField::toString() const {
    return this->getKey() + ": " +  this->getValue();
}


AbstractFlowRouteField::AbstractFlowRouteField(string value) {
    if (value.empty()) return;
    this->setValue.insert(value);
}



AbstractFlowRouteField::AbstractFlowRouteField(set<string> setValue) {
    this->setValue = setValue;
}

string AbstractFlowRouteField::getValue() const {
    string output = "";
    bool first = true;
    for (auto f : this->setValue) {
        if (!first) output += ";";
        output+= f;
        first = false;
    }
    return output;
}
