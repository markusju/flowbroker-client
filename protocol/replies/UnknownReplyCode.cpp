//
// Created by Markus Jungbluth on 14.06.16.
//

#include "UnknownReplyCode.h"
#include "../exceptions/BrokerReplyEvaluationErrorException.h"

UnknownReplyCode::UnknownReplyCode(int code) {
    this->replyCode = code;
    switch (this->getFirstDigit()) {
        case 1:
            throw BrokerReplyEvaluationErrorException("Code 1XX not (yet) implemented!");
        case 2:
            break; //Permitted
        case 3:
            throw BrokerReplyEvaluationErrorException("Code 3XX not (yet) implemented!");
        case 4:
            break; //Permitted
        case 5:
            break; //Permitted
        default:
            throw BrokerReplyEvaluationErrorException("Code not implemented!");
    }

}

bool UnknownReplyCode::isSuccessful() {
    switch(this->getFirstDigit()) {
        case 2:
            return true;
        case 4:
            return false;
        case 5:
            return false;
        default:
            throw BrokerReplyEvaluationErrorException("Illegal State");
    }
}

bool UnknownReplyCode::isInformational() {
    switch(this->getFirstDigit()) {
        case 2:
            return false;
        case 4:
            return false;
        case 5:
            return false;
        default:
            throw BrokerReplyEvaluationErrorException("Illegal State");
    }
}

bool UnknownReplyCode::isFailed() {
    switch(this->getFirstDigit()) {
        case 2:
            return false;
        case 4:
            return true;
        case 5:
            return true;
        default:
            throw BrokerReplyEvaluationErrorException("Illegal State");
    }
}

bool UnknownReplyCode::isMyFault() {
    switch(this->getFirstDigit()) {
        case 2:
            return false;
        case 4:
            return true;
        case 5:
            return false;
        default:
            throw BrokerReplyEvaluationErrorException("Illegal State");
    }
}

string UnknownReplyCode::getStandardMessage() {
    return "CODE SENT BY SERVER UNKNOWN TO CLIENT";
}

string UnknownReplyCode::getDetailedExplanation() {
    return "Code sent by Server is unkown, but adheres to the protocol standard. Client is interpreting it according to the standard.";
}
