//
// Created by Markus Jungbluth on 17.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_HMACVERIFICATIONFAILEDERROREXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_HMACVERIFICATIONFAILEDERROREXCEPTION_H


#include <stdexcept>

using namespace std;

class HMACVerificationFailedErrorException  : public runtime_error {
public:
    HMACVerificationFailedErrorException(const char *msg) : runtime_error(msg) {}
    HMACVerificationFailedErrorException (string& msg) : runtime_error(msg) {}
};


#endif //BROKER_PROTOCOL_CLIENT_HMACVERIFICATIONFAILEDERROREXCEPTION_H
