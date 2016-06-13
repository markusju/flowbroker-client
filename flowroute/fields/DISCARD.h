//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_DISCARD_H
#define BROKER_PROTOCOL_CLIENT_DISCARD_H


#include "types/AbstractFlowRouteAction.h"
#include "SourceAddress.h"

class DISCARD : public AbstractFlowRouteAction {

public:
    virtual string getMethod() const;

    DISCARD(SourceAddress* sourceAddress);

private:
    SourceAddress* sourceAddress;

};


#endif //BROKER_PROTOCOL_CLIENT_DISCARD_H
