//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_REPLYCODE_H
#define BROKER_PROTOCOL_CLIENT_REPLYCODE_H


#include <string>

using namespace std;

class ReplyCode {
public:
    virtual bool isSuccessful() = 0;
    virtual bool isInformational() = 0;
    virtual bool isFailed() = 0;
    virtual bool isMyFault() = 0;

    virtual int getCode();
    virtual int getFirstDigit();

    virtual string getStandardMessage() = 0;
    virtual string getDetailedExplanation() = 0;

protected:
    int replyCode;
};


#endif //BROKER_PROTOCOL_CLIENT_REPLYCODE_H
