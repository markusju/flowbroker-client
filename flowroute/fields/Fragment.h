//
// Created by Markus Jungbluth on 11.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_FRAGMENT_H
#define BROKER_PROTOCOL_CLIENT_FRAGMENT_H


#include "AbstractSetOfThings.h"

class Fragment : public AbstractSetOfThings{
public:
    Fragment(string value);
    string getKey() const;

protected:
    set<string> getThings();
};


#endif //BROKER_PROTOCOL_CLIENT_FRAGMENT_H
