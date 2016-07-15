//
// Created by Markus Jungbluth on 15.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_CLIENTERROREXCEPTION_H
#define BROKER_PROTOCOL_CLIENT_CLIENTERROREXCEPTION_H

#include <stdexcept>

using namespace std;

class ClientErrorException : public runtime_error {
public:
    ClientErrorException(const char *msg) : runtime_error(msg) {}
    ClientErrorException(string& msg) : runtime_error(msg) {}

};

#endif //BROKER_PROTOCOL_CLIENT_CLIENTERROREXCEPTION_H
