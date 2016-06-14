//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_UNKNOWNREPLYCODE_H
#define BROKER_PROTOCOL_CLIENT_UNKNOWNREPLYCODE_H


#include "type/ReplyCode.h"

class UnknownReplyCode : public ReplyCode {
public:
    UnknownReplyCode(int code);

    virtual bool isSuccessful();
    virtual bool isInformational();
    virtual bool isFailed();
    virtual bool isMyFault();

    virtual string getStandardMessage();
    virtual string getDetailedExplanation();
};


#endif //BROKER_PROTOCOL_CLIENT_UNKNOWNREPLYCODE_H
