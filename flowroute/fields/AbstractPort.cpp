//
// Created by Markus Jungbluth on 03.07.16.
//

#include "AbstractPort.h"

AbstractPort::AbstractPort(string value) : AbstractFlowRouteField(value) {
    //Analyzes the already processesed string...
    portExpression.analyze(setValue);
}
