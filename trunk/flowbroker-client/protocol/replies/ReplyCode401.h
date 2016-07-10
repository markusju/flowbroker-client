//
// Created by Markus Jungbluth on 09.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_REPLYCODE401_H
#define BROKER_PROTOCOL_CLIENT_REPLYCODE401_H


#include "type/ReplyCode.h"

class ReplyCode401 : public ReplyCode {
public:
    ReplyCode401();
    virtual bool isSuccessful();
    virtual bool isInformational();
    virtual bool isFailed();
    virtual bool isMyFault();

    virtual string getStandardMessage();
    virtual string getDetailedExplanation();
};


#endif //BROKER_PROTOCOL_CLIENT_REPLYCODE401_H
