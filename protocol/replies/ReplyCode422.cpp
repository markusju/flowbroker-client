//
// Created by Markus Jungbluth on 09.07.16.
//

#include "ReplyCode422.h"

ReplyCode422::ReplyCode422() {
    this->replyCode = 422;
}

bool ReplyCode422::isSuccessful() {
    return false;
}

bool ReplyCode422::isInformational() {
    return false;
}

bool ReplyCode422::isFailed() {
    return true;
}

bool ReplyCode422::isMyFault() {
    return true;
}

string ReplyCode422::getStandardMessage() {
    return "SEMANTIC ERRORS";
}

string ReplyCode422::getDetailedExplanation() {
    return "Something went horribly wrong. Either your client or the server is not adhering to the Broker Protocol. Please contact a developer.";
}
