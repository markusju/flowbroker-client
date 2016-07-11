//
// Created by Markus Jungbluth on 10.06.16.
//

#include "AbstractFlowRouteField.h"
#include "../../../helper/stringHelper.h"

string AbstractFlowRouteField::toString() const {
    return this->getKey() + ": " +  this->getValue();
}


AbstractFlowRouteField::AbstractFlowRouteField(string value) {
    if (value.empty()) return;
    vector<string> elems = stringHelper::split(value,';');

    for (auto el : elems) {
        setValue.insert(el);
    }
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
