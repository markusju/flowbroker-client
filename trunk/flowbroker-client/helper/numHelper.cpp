//
// Created by Markus Jungbluth on 03.07.16.
//

#include "numHelper.h"



namespace numHelper {

    bool is_number(const string &s) {
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

}