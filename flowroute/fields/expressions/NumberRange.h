//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_NUMBERRANGE_H
#define BROKER_PROTOCOL_CLIENT_NUMBERRANGE_H


#include <string>

using namespace std;

class NumberRange {

public:
    void analyze(string input);
protected:
    virtual void analzyeElement(string element) = 0;

};


#endif //BROKER_PROTOCOL_CLIENT_NUMBERRANGE_H
