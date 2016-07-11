//
// Created by Markus Jungbluth on 11.07.16.
//

#include "ICMPType.h"

ICMPType::ICMPType(string value) : AbstractSetOfThings(value) {
    this->checkValue();
}

string ICMPType::getKey() const {
    return "ICMP-Type";
}

set<string> ICMPType::getThings() {
    return {"echo-reply", "echo-request", "info-reply", "info-request", "mask-reply",
            "mask-request", "parameter-problem", "redirect", "router-advertisement",
            "router-solicit", "source-quench", "time-exceeded", "timestamp", "timestamp-reply",
            "unreachable"};
}
