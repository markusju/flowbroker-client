//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode408.h"

ReplyCode408::ReplyCode408() {
    this->replyCode = 408;
}

bool ReplyCode408::isSuccessful() {
    return false;
}

bool ReplyCode408::isInformational() {
    return false;
}

bool ReplyCode408::isFailed() {
    return true;
}

bool ReplyCode408::isMyFault() {
    return true;
}

string ReplyCode408::getStandardMessage() {
    return "REQUEST TIMED OUT";
}

string ReplyCode408::getDetailedExplanation() {
    return "The client took too long to send its request. The server closed the connection. This is not supposed to happen. Please contact a developer.";
}
