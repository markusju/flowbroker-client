//
// Created by Markus Jungbluth on 09.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_REPLYCODE501_H
#define BROKER_PROTOCOL_CLIENT_REPLYCODE501_H


#include "type/ReplyCode.h"

class ReplyCode501 : public ReplyCode {
public:
    ReplyCode501();
    virtual bool isSuccessful();
    virtual bool isInformational();
    virtual bool isFailed();
    virtual bool isMyFault();

    virtual string getStandardMessage();
    virtual string getDetailedExplanation();
};


#endif //BROKER_PROTOCOL_CLIENT_REPLYCODE501_H
