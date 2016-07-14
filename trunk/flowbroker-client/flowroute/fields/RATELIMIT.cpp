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


    // RATELIMIT 9600 8.8.8.8/32
    // Push_back inserts at the end!!

    this->methodArguments.push_back(to_string(this->rate));
    this->methodArguments.push_back(this->sourceAddress->getValue());

}
