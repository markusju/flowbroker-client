//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode404.h"

ReplyCode404::ReplyCode404() {
    this->replyCode = 404;
}

bool ReplyCode404::isSuccessful() {
    return false;
}

bool ReplyCode404::isInformational() {
    return false;
}

bool ReplyCode404::isFailed() {
    return true;
}

bool ReplyCode404::isMyFault() {
    return true;
}

string ReplyCode404::getStandardMessage() {
    return "NOT FOUND";
}

string ReplyCode404::getDetailedExplanation() {
    return "The specified Flow Specification could not be withdrawn, as no matching specification could be found on the server.";
}
