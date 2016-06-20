//
// Created by Markus Jungbluth on 20.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_DATEVALIDATIONFAILEDERROREXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_DATEVALIDATIONFAILEDERROREXCEPTION_H



#include <stdexcept>

using namespace std;


class DateValidationFailedErrorException : public runtime_error {
public:
    DateValidationFailedErrorException (const char *msg) : runtime_error(msg) {}
    DateValidationFailedErrorException (string& msg) : runtime_error(msg) {}
};



#endif //BROKER_PROTOCOL_CLIENT_DATEVALIDATIONFAILEDERROREXCEPTION_H
