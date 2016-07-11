//
// Created by Markus Jungbluth on 11.07.16.
//

#include "DSCP.h"

DSCP::DSCP(string value) : AbstractFlowRouteField(value){
    dscpExpression.analyze(setValue);
}

string DSCP::getKey() const {
    return "DSCP";
}
