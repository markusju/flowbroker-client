//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_ICMPTYPE_H
#define BROKER_PROTOCOL_CLIENT_ICMPTYPE_H


#include "AbstractSetOfThings.h"

class ICMPType : public AbstractSetOfThings{
public:
    ICMPType(string value);
    string getKey() const;

protected:
    set<string> getThings();
};


#endif //BROKER_PROTOCOL_CLIENT_ICMPTYPE_H
