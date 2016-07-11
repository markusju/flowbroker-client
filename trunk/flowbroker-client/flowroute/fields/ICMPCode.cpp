//
// Created by Markus Jungbluth on 11.07.16.
//

#include "ICMPCode.h"

ICMPCode::ICMPCode(string value) : AbstractSetOfThings(value) {
    this->checkValue();
}

string ICMPCode::getKey() const {
    return "ICMP-Code";
}

set<string> ICMPCode::getThings() {
    return {"communication-prohibited-by-filtering", "destination-host-prohibited ", "destination-host-unknown ",
            "destination-network-unknown ", "fragmentation-needed ", "host-precedence-violation",
            "ip-header-bad", "network-unreachable", "network-unreachable-for-tos ",
            "port-unreachable", "redirect-for-host","redirect-for-network",
            "redirect-for-tos-and-host", "redirect-for-tos-and-net", "required-option-missing",
            "source-host-isolated", "source-route-failed", "ttl-eq-zero-during-reassembly",
            "ttl-eq-zero-during-transit"};
}
