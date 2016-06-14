//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLYEVALUATIONERROREXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLYEVALUATIONERROREXCEPTION_H

#include <stdexcept>

using namespace std;

class BrokerReplyEvaluationErrorException : public runtime_error {
public:
    BrokerReplyEvaluationErrorException (const char *msg) : runtime_error(msg) {}
    BrokerReplyEvaluationErrorException (string& msg) : runtime_error(msg) {}
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLYEVALUATIONERROREXCEPTION_H
