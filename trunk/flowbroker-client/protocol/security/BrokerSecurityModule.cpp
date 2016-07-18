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

BrokerSecurityModule::BrokerSecurityModule(string secret, long toleranceMillis) : mac(secret), date(toleranceMillis) {

}

void BrokerSecurityModule::validateDate(BrokerReply *brokerReply) {
    if (brokerReply->getParameters().count("Date")) {
        string date = brokerReply->getParameters()["Date"];
        this->date.checkTimeStamp(date);
        return;
    }

    throw DateValidationFailedErrorException("Server did not supply a timestamp. Replay attack checks could not be performed!");
}

void BrokerSecurityModule::signRequest(BrokerRequest *brokerRequest) {
    string hmac = this->mac.getMacForMessage(brokerRequest->toString());
    brokerRequest->addParameter("Signature", hmac);
}

void BrokerSecurityModule::setDate(BrokerRequest *brokerRequest) {
    brokerRequest->addParameter("Date", date.getCurrentTimeStamp());
}
