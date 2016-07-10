//
// Created by Markus Jungbluth on 09.07.16.
//

#include "ReplyCode501.h"

ReplyCode501::ReplyCode501() {
    this->replyCode = 501;
}

bool ReplyCode501::isSuccessful() {
    return false;
}

bool ReplyCode501::isInformational() {
    return false;
}

bool ReplyCode501::isFailed() {
    return true;
}

bool ReplyCode501::isMyFault() {
    return true;
}

string ReplyCode501::getStandardMessage() {
    return "NOT IMPLEMENTED";
}

string ReplyCode501::getDetailedExplanation() {
    return "The server could not complete your request, as the request method you used is not implemented.";
}
