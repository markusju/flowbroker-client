//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_NUMHELPER_H
#define BROKER_PROTOCOL_CLIENT_NUMHELPER_H

#include <string>

using namespace std;

namespace numHelper {
    /**
     * Checks whether a supplied string contains a number
     * @param s
     * @return
     */
    bool is_number(const string &s);

}
#endif //BROKER_PROTOCOL_CLIENT_NUMHELPER_H
