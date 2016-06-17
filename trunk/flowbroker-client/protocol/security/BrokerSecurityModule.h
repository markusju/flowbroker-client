//
// Created by Markus Jungbluth on 17.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERSECURITYMODULE_H
#define BROKER_PROTOCOL_CLIENT_BROKERSECURITYMODULE_H


#include "../BrokerReply.h"
#include "MessageAuthenticationCode.h"
#include "../BrokerRequest.h"

class BrokerSecurityModule {
public:
    BrokerSecurityModule(string secret);

    void validateDate(BrokerReply *brokerReply);
    void validateSignature(BrokerReply *brokerReply);

    void signRequest(BrokerRequest* brokerRequest);
    void setDate(BrokerRequest* brokerRequest);

private:
    MessageAuthenticationCode mac;
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERSECURITYMODULE_H
