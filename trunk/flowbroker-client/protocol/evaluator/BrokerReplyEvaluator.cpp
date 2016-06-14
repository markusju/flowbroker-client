//
// Created by Markus Jungbluth on 14.06.16.
//

#include "BrokerReplyEvaluator.h"
#include "../replies/ReplyCode200.h"
#include "../replies/UnknownReplyCode.h"
#include "../replies/ReplyCode400.h"

BrokerReplyEvaluator::BrokerReplyEvaluator() {

}


ReplyCode* BrokerReplyEvaluator::evaluate(BrokerReply *brokerReply) {
    int code = brokerReply->getStatusCode();
    ReplyCode200 a;
    switch(code) {
        case 200:
            return new ReplyCode200();
        case 400:
            return new ReplyCode400();
        default:
            return new UnknownReplyCode(code);

    }

}
