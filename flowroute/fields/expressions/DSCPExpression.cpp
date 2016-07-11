//
// Created by Markus Jungbluth on 11.07.16.
//

#include "DSCPExpression.h"
#include "../../exceptions/FlowRouteException.h"

void DSCPExpression::checkPortNumber(int port) {
    if (!(port > 0 && port <= 65535)) throw FlowRouteException("Invalid DSCP Number");
}
