//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_FLOWROUTEFIELD_H
#define BROKER_PROTOCOL_CLIENT_FLOWROUTEFIELD_H

#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;


class AbstractFlowRouteField {
public:
    virtual string toString() const;
    /**
     * A Broker-Protocol compliant <Value> for a Parameter Set
     */
    virtual string getKey() const = 0;
    /**
     * A Broker-Protocol compliant <Key> for a Parameter Set
     */
    virtual string getValue() const;

protected:
    set<string> setValue;

    AbstractFlowRouteField() : AbstractFlowRouteField("") { }
    AbstractFlowRouteField(string value);
    AbstractFlowRouteField(set<string> setValue);

};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTEFIELD_H
