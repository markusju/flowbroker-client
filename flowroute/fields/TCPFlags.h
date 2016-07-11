//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_TCPFLAGS_H
#define BROKER_PROTOCOL_CLIENT_TCPFLAGS_H


#include "AbstractSetOfThings.h"

class TCPFlags : public AbstractSetOfThings{
public:
    TCPFlags(string value);
    string getKey() const;

protected:
    set<string> getThings();
};


#endif //BROKER_PROTOCOL_CLIENT_TCPFLAGS_H
