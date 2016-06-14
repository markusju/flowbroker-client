//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode403.h"

ReplyCode403::ReplyCode403() {
    this->replyCode = 403;
}

bool ReplyCode403::isSuccessful() {
    return false;
}

bool ReplyCode403::isInformational() {
    return false;
}

bool ReplyCode403::isFailed() {
    return true;
}

bool ReplyCode403::isMyFault() {
    return true;
}

string ReplyCode403::getStandardMessage() {
    return "FORBIDDEN";
}

string ReplyCode403::getDetailedExplanation() {
    return "Indicates that the client sent a request which does not comply with the security policies of the server.";
}
