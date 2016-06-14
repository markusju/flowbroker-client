//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_REPLYCODE400_H
#define BROKER_PROTOCOL_CLIENT_REPLYCODE400_H


#include "type/ReplyCode.h"

class ReplyCode400 : public ReplyCode {
public:
    ReplyCode400();
    virtual bool isSuccessful();
    virtual bool isInformational();
    virtual bool isFailed();
    virtual bool isMyFault();

    virtual string getStandardMessage();
    virtual string getDetailedExplanation();
};


#endif //BROKER_PROTOCOL_CLIENT_REPLYCODE400_H
