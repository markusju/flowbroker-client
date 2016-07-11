//
// Created by Markus Jungbluth on 11.07.16.
//

#include "Fragment.h"

Fragment::Fragment(string value) : AbstractSetOfThings(value) {
    this->checkValue();
}

set<string> Fragment::getThings() {
    return {"not-a-fragment", "dont-fragment",
            "is-fragment", "first-fragment",
            "last-fragment"};
}

string Fragment::getKey() const {
    return "Fragment";
}
