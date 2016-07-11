//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_DSCPEXPRESSION_H
#define BROKER_PROTOCOL_CLIENT_DSCPEXPRESSION_H


#include "PortExpression.h"

class DSCPExpression : public PortExpression {
protected:
    virtual void checkPortNumber(int port);

};


#endif //BROKER_PROTOCOL_CLIENT_DSCPEXPRESSION_H
