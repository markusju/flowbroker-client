//
// Created by Markus Jungbluth on 13.06.16.
//

#include "BrokerRequest.h"

BrokerRequest::BrokerRequest(string method) {
    this->requestMethod = method;

}

string BrokerRequest::toString() const {
    string output;
    output.reserve(8192);

    output.append(this->requestMethod);


    for (auto el : this->requestArguments) {
        output.append(" ");
        output.append(el);
    }


    for (auto el : this->parameters) {
        output.append("\n");
        output.append(el.first + ": " + el.second);
    }

    output.append("\n\n");

    return output;
}

