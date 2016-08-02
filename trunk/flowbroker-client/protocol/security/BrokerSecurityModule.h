//
// Created by Markus Jungbluth on 17.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERSECURITYMODULE_H
#define BROKER_PROTOCOL_CLIENT_BROKERSECURITYMODULE_H


#include "../BrokerReply.h"
#include "MessageAuthenticationCode.h"
#include "../BrokerRequest.h"
#include "BrokerDate.h"

class BrokerSecurityModule {
public:
    BrokerSecurityModule(string secret, long toleranceMillis);

    /**
     * Validates the Timestamp contained in a BrokerReply object
     * @param brokerReply
     */
    void validateDate(BrokerReply *brokerReply);
    /**
     * Validates the signature of a supllied BrokerReply object
     * @param brokerReply
     */
    void validateSignature(BrokerReply *brokerReply);

    /**
     * Signs a BrokerRequest (HMAC)
     * @param brokerRequest
     */
    void signRequest(BrokerRequest* brokerRequest);
    /**
     * Sets a Date-Parameter on the supplied BrokerRequest object
     * @param brokerRequest
     */
    void setDate(BrokerRequest* brokerRequest);

private:
    MessageAuthenticationCode mac;
    BrokerDate date;
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERSECURITYMODULE_H
