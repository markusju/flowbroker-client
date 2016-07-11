//
// Created by Markus Jungbluth on 11.07.16.
//

#include "TCPFlags.h"

set<string> TCPFlags::getThings() {
    return {"fin", "syn", "rst", "push", "ack", "urgent"};
}

string TCPFlags::getKey() const {
    return "TCP-Flags";
}

TCPFlags::TCPFlags(string value) : AbstractSetOfThings(value) {
    this->checkValue();
}
