//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_ICMPCODE_H
#define BROKER_PROTOCOL_CLIENT_ICMPCODE_H


#include "AbstractSetOfThings.h"

class ICMPCode : public AbstractSetOfThings{
public:
    ICMPCode(string value);
    string getKey() const;

protected:
    set<string> getThings();
};



#endif //BROKER_PROTOCOL_CLIENT_ICMPCODE_H
