//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PORTEXPRESSION_H
#define BROKER_PROTOCOL_CLIENT_PORTEXPRESSION_H


#include <set>
#include "NumberRange.h"

class PortExpression : public NumberRange {


public:

protected:
    void analyzeElement(string element);
    virtual void checkPortNumber(int port);
    virtual void checkPrefix(char prefix);

};


#endif //BROKER_PROTOCOL_CLIENT_PORTEXPRESSION_H
