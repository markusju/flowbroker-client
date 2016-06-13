//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_NAME_H
#define BROKER_PROTOCOL_CLIENT_NAME_H

#include <string>

using namespace std;

class Name {
private:
    string name;
public:

    Name(const string &name) : name(name) {

    }

    const string &getName() const {
        return name;
    }
};


#endif //BROKER_PROTOCOL_CLIENT_NAME_H
