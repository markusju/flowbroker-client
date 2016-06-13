//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_ABSTRACTADDRESS_H
#define BROKER_PROTOCOL_CLIENT_ABSTRACTADDRESS_H


#include <string>
#include <regex>
#include "types/AbstractFlowRouteField.h"

using namespace std;

class AbstractAddress : public AbstractFlowRouteField {
private:
    regex* reg = new regex("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])(\\/([0-9]|[1-2][0-9]|3[0-2]))$");

public:
    AbstractAddress(string value);

};


#endif //BROKER_PROTOCOL_CLIENT_ABSTRACTADDRESS_H
