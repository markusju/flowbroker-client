//
// Created by Markus Jungbluth on 17.06.16.
//

#include "MessageAuthenticationCode.h"
#include "hash-library/hmac.h"
#include "hash-library/sha256.h"
#include "exceptions/HMACVerificationFailedErrorException.h"

MessageAuthenticationCode::MessageAuthenticationCode(string secret) {
    this->secret = secret;

}

string MessageAuthenticationCode::getMacForMessage(string message) {
    return hmac<SHA256>(message, this->secret);
}

void MessageAuthenticationCode::checkMacForMessage(string suppliedMac, string message) {
    string calculatedMac = this->getMacForMessage(message);
    if (calculatedMac != suppliedMac) throw HMACVerificationFailedErrorException("HMAC is incorrect.");
}
