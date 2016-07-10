//
// Created by Markus Jungbluth on 09.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_WITHDRAW_H
#define BROKER_PROTOCOL_CLIENT_WITHDRAW_H


#include "types/AbstractFlowRouteAction.h"
#include "SourceAddress.h"

class WITHDRAW : public AbstractFlowRouteAction {

public:
    virtual string getMethod() const;
    WITHDRAW(SourceAddress* sourceAddress);

private:
    SourceAddress* sourceAddress;

};

#endif //BROKER_PROTOCOL_CLIENT_WITHDRAW_H
