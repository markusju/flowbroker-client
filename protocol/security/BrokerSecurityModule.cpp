//
// Created by Markus Jungbluth on 17.06.16.
//

#include "BrokerSecurityModule.h"
#include "exceptions/HMACVerificationFailedErrorException.h"
#include "exceptions/DateValidationFailedErrorException.h"

void BrokerSecurityModule::validateSignature(BrokerReply *brokerReply) {
    //If exists
    if (brokerReply->getParameters().count("Signature")) {
        string signature = brokerReply->getParameters()["Signature"];
        this->mac.checkMacForMessage(signature, brokerReply->toStringForSignatureValidation());
        return;
    }


    throw HMACVerificationFailedErrorException("No Signature Parameter supplied");
}

BrokerSecurityModule::BrokerSecurityModule(string secret) : mac(secret) {

}

void BrokerSecurityModule::validateDate(BrokerReply *brokerReply) {

    //If exists
    if (brokerReply->getParameters().count("Date")) {
        //TODO
        return;
    }

    throw DateValidationFailedErrorException("Server supplied a signed timestamp which is too old. This could be a replay attack.");
}

void BrokerSecurityModule::signRequest(BrokerRequest *brokerRequest) {
    string hmac = this->mac.getMacForMessage(brokerRequest->toString());
    brokerRequest->addParameter("Signature", hmac);
}

void BrokerSecurityModule::setDate(BrokerRequest *brokerRequest) {
    brokerRequest->addParameter("Date", "123456789");
}
