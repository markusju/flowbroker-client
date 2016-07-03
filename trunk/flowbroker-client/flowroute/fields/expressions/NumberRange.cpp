//
// Created by Markus Jungbluth on 03.07.16.
//

#include "NumberRange.h"
#include "../../../helper/stringHelper.h"
#include "../../exceptions/FlowRouteException.h"


void NumberRange::analyze(string input) {
    vector<string> tokens = stringHelper::split(input, '&');

    if (tokens.size() < 1) {
        throw FlowRouteException("Invalid NumberRangeExpression");
    }

    for (auto el : tokens) {
        analzyeElement(el);
    }
}
