//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_PROTOCOL_H
#define BROKER_PROTOCOL_CLIENT_PROTOCOL_H


#include "types/AbstractFlowRouteField.h"
#include "AbstractSetOfThings.h"
#include <string>

class Protocol: public AbstractSetOfThings{
public:
    Protocol(string value);
    string getKey() const;

protected:
    set<string> getThings();
};



#endif //BROKER_PROTOCOL_CLIENT_PROTOCOL_H
