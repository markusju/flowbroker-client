//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_ABSTRACTPORT_H
#define BROKER_PROTOCOL_CLIENT_ABSTRACTPORT_H


#include <string>
#include "types/AbstractFlowRouteField.h"
#include "AbstractAddress.h"
#include "expressions/PortExpression.h"

using namespace std;

class AbstractPort : public AbstractFlowRouteField {

public:
    AbstractPort(string value);
private:
    PortExpression portExpression;

};


#endif //BROKER_PROTOCOL_CLIENT_ABSTRACTPORT_H
