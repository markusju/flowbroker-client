//
// Created by Markus Jungbluth on 09.07.16.
//

#include "ReplyCode401.h"

bool ReplyCode401::isSuccessful() {
    return false;
}

bool ReplyCode401::isInformational() {
    return false;
}

bool ReplyCode401::isFailed() {
    return true;
}

bool ReplyCode401::isMyFault() {
    return true;
}

string ReplyCode401::getStandardMessage() {
    return "UNAUTHORIZED";
}

string ReplyCode401::getDetailedExplanation() {
    return "Your request seems to carry an invalid signature. Make sure the defined secret is correct and your system clock is properly synchronized.";
}

ReplyCode401::ReplyCode401() {
    replyCode = 401;

}