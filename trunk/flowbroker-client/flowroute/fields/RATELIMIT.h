//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_RATELIMIT_H
#define BROKER_PROTOCOL_CLIENT_RATELIMIT_H


#include "SourceAddress.h"
#include "types/AbstractFlowRouteAction.h"

class RATELIMIT : public AbstractFlowRouteAction {
public:
    virtual string getMethod() const;

    RATELIMIT(SourceAddress* sourceAddress, int rate);

private:
    SourceAddress* sourceAddress;
    int rate;

};

#endif //BROKER_PROTOCOL_CLIENT_RATELIMIT_H
