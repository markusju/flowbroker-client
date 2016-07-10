//
// Created by Markus Jungbluth on 09.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_REPLYCODE422_H
#define BROKER_PROTOCOL_CLIENT_REPLYCODE422_H


#include "type/ReplyCode.h"

class ReplyCode422 : public ReplyCode {
public:
    ReplyCode422();
    virtual bool isSuccessful();
    virtual bool isInformational();
    virtual bool isFailed();
    virtual bool isMyFault();

    virtual string getStandardMessage();
    virtual string getDetailedExplanation();
};

#endif //BROKER_PROTOCOL_CLIENT_REPLYCODE422_H
