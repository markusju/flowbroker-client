//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLYEVALUATOR_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLYEVALUATOR_H


#include "../BrokerReply.h"
#include "../replies/type/ReplyCode.h"
#include "../replies/ReplyCode200.h"

class BrokerReplyEvaluator {

public:
    BrokerReplyEvaluator();
    /**
     * Evaluates a BrokerReply and returns a ReplyCode object (Pointer)
     * @param brokerReply
     * @return
     */
    ReplyCode* evaluate(BrokerReply* brokerReply);
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLYEVALUATOR_H
