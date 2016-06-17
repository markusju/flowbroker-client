//
// Created by Markus Jungbluth on 17.06.16.
//

#include "Expires.h"

Expires::Expires(int expires) : AbstractFlowRouteField(to_string(expires)){

}

string Expires::getKey() const {
    return "Expires";
}
