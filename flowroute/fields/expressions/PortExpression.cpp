//
// Created by Markus Jungbluth on 03.07.16.
//

#include "PortExpression.h"
#include "../../../helper/stringHelper.h"
#include "../../exceptions/FlowRouteException.h"
#include "../../../helper/numHelper.h"

void PortExpression::analyzeElement(string element) {
    string input = stringHelper::trim(element);

    if (numHelper::is_number(input)) {
        if (getTokens().size() != 1) throw FlowRouteException("Invalid Port Expression");
        checkPortNumber(stoi(input));
        return;
    }

    char prefix = input[0];
    checkPrefix(prefix);

    input.erase(0,1);
    checkPortNumber(stoi(input));
}

void PortExpression::checkPortNumber(int port) {
    if (!(port > 0 && port <= 65535)) throw FlowRouteException("Invalid Port Number");
}

void PortExpression::checkPrefix(char prefix) {
    if (prefix == '>') return;
    if (prefix == '<') return;
    if (prefix == '=') return;

    throw FlowRouteException("Invalid Prefix");
}
