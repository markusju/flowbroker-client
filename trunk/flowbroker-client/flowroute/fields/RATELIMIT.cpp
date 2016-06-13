//
// Created by Markus Jungbluth on 13.06.16.
//

#include "RATELIMIT.h"

string RATELIMIT::getMethod() const {
    return "RATELIMIT";
}

RATELIMIT::RATELIMIT(SourceAddress *sourceAddress, int rate) {

    this->sourceAddress = sourceAddress;
    this->rate = rate;


    this->methodArguments.insert(to_string(this->rate));
    this->methodArguments.insert(this->sourceAddress->getValue());

}
