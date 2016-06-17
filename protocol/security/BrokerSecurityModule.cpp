//
// Created by Markus Jungbluth on 17.06.16.
//

#include "BrokerSecurityModule.h"
#include "exceptions/HMACVerificationFailedErrorException.h"

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

}

void BrokerSecurityModule::signRequest(BrokerRequest *brokerRequest) {

}

void BrokerSecurityModule::setDate(BrokerRequest *brokerRequest) {

}
