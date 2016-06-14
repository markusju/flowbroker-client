//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode200.h"

string ReplyCode200::getStandardMessage() {
    return "SUCCESS";
}

string ReplyCode200::getDetailedExplanation() {
    return "Your request was completed successfully.";
}

bool ReplyCode200::isMyFault() {
    return false;
}

bool ReplyCode200::isFailed() {
    return false;
}

bool ReplyCode200::isInformational() {
    return false;
}

bool ReplyCode200::isSuccessful() {
    return true;
}

ReplyCode200::ReplyCode200() {
    replyCode = 200;

}
