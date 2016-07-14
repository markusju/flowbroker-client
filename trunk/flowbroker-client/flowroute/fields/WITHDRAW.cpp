//
// Created by Markus Jungbluth on 13.06.16.
//

#include "WITHDRAW.h"



string WITHDRAW::getMethod() const {
    return "WITHDRAW";
}

WITHDRAW::WITHDRAW(SourceAddress *sourceAddress) {
    this->sourceAddress = sourceAddress;
    this->methodArguments.push_back(this->sourceAddress->getValue());
}
