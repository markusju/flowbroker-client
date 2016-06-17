//
// Created by Markus Jungbluth on 17.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_EXPIRES_H
#define BROKER_PROTOCOL_CLIENT_EXPIRES_H


#include "types/AbstractFlowRouteField.h"

class Expires : public AbstractFlowRouteField {
public:
    Expires(int expires);
    virtual string getKey() const;
};


#endif //BROKER_PROTOCOL_CLIENT_EXPIRES_H
