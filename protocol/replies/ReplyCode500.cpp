//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode500.h"

ReplyCode500::ReplyCode500() {
    this->replyCode = 500;
}

bool ReplyCode500::isSuccessful() {
    return false;
}

bool ReplyCode500::isInformational() {
    return false;
}

bool ReplyCode500::isFailed() {
    return true;
}

bool ReplyCode500::isMyFault() {
    return true;
}

string ReplyCode500::getStandardMessage() {
    return "INTERNAL SERVER ERROR";
}

string ReplyCode500::getDetailedExplanation() {
    return "The server was not able to process your request due to internal errors.";
}
