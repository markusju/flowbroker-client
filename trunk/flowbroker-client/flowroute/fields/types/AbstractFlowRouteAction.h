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

    /**
     * A string containing the method name.
     * @return
     */
    virtual string getMethod() const = 0;
    /**
     * Returns the method arguments of the FlowRouteAction
     * @return A vector containing the method arguments
     */
    virtual vector<string> getMethodArguments() const;
    /**
     * Returns a string representation of the FlowRouteAction
     * @return
     */
    virtual string toString() const;

protected:
    vector<string> methodArguments;
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTEACTION_H
