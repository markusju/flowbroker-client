//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_ABSTRACTSETOFTHINGS_H
#define BROKER_PROTOCOL_CLIENT_ABSTRACTSETOFTHINGS_H


#include "types/AbstractFlowRouteField.h"

class AbstractSetOfThings : public AbstractFlowRouteField {

protected:
    AbstractSetOfThings(string basic_string);
    void checkValue();
    virtual set<string> getThings() = 0;
};


#endif //BROKER_PROTOCOL_CLIENT_ABSTRACTSETOFTHINGS_H
