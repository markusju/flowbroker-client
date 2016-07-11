//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_DSCP_H
#define BROKER_PROTOCOL_CLIENT_DSCP_H


#include "types/AbstractFlowRouteField.h"
#include "expressions/DSCPExpression.h"

class DSCP : public AbstractFlowRouteField {

public:
    DSCP(string value);
    string getKey() const;
private:
    DSCPExpression dscpExpression;

};


#endif //BROKER_PROTOCOL_CLIENT_DSCP_H
