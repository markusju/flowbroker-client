//
// Created by Markus Jungbluth on 13.06.16.
//

#include "DISCARD.h"



string DISCARD::getMethod() const {
    return "DISCARD";
}

DISCARD::DISCARD(SourceAddress *sourceAddress) {
    this->sourceAddress = sourceAddress;
    this->methodArguments.insert(this->sourceAddress->getValue());
}
