//
// Created by Markus Jungbluth on 13.06.16.
//

#include "BrokerReply.h"

BrokerReply::BrokerReply() {


}

string BrokerReply::toStringForSignatureValidation() const {
    string out;
    out +=to_string(this->statusCode)+" "+this->message;
    for (auto el : this->parameters) {
        if (el.first == "Signature") continue;
        out+="\n";
        out+=el.first+": "+el.second;
    }
    return out;

}
