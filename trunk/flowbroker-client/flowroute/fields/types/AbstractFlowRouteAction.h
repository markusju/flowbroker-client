//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_FLOWROUTEACTION_H
#define BROKER_PROTOCOL_CLIENT_FLOWROUTEACTION_H

#include <set>
#include <string>
#include <vector>

using namespace std;

class AbstractFlowRouteAction {
public:

    virtual string getMethod() const = 0;
    virtual vector<string> getMethodArguments() const;
    virtual string toString() const;

protected:
    vector<string> methodArguments;
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTEACTION_H
