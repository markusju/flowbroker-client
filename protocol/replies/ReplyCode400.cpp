//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode400.h"

bool ReplyCode400::isSuccessful() {
    return false;
}

bool ReplyCode400::isInformational() {
    return false;
}

bool ReplyCode400::isFailed() {
    return true;
}

bool ReplyCode400::isMyFault() {
    return true;
}

string ReplyCode400::getStandardMessage() {
    return "BAD REQUEST";
}

string ReplyCode400::getDetailedExplanation() {
    return "The client's request was malformed. This indicates a syntactical error in the client's request.";
}

ReplyCode400::ReplyCode400() {
    replyCode = 400;

}
