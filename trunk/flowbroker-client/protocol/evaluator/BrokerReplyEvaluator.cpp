//
// Created by Markus Jungbluth on 14.06.16.
//

#include "BrokerReplyEvaluator.h"
#include "../replies/ReplyCode200.h"
#include "../replies/UnknownReplyCode.h"
#include "../replies/ReplyCode400.h"
#include "../replies/ReplyCode403.h"
#include "../replies/ReplyCode401.h"
#include "../replies/ReplyCode500.h"
#include "../replies/ReplyCode501.h"
#include "../replies/ReplyCode422.h"
#include "../replies/ReplyCode408.h"
#include "../replies/ReplyCode404.h"

BrokerReplyEvaluator::BrokerReplyEvaluator() {

}


ReplyCode* BrokerReplyEvaluator::evaluate(BrokerReply *brokerReply) {
    int code = brokerReply->getStatusCode();
    switch(code) {
        case 200:
            return new ReplyCode200();
        case 400:
            return new ReplyCode400();
        case 401:
            return new ReplyCode401();
        case 403:
            return new ReplyCode403();
        case 404:
            return new ReplyCode404();
        case 408:
            return new ReplyCode408();
        case 422:
            return new ReplyCode422();
        case 500:
            return new ReplyCode500();
        case 501:
            return new ReplyCode501();
        default:
            return new UnknownReplyCode(code);

    }

}
