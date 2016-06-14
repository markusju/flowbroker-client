//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H
#define BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H

#include <string>
#include <list>
#include <map>
#include <set>

using namespace std;


class BrokerRequest {



public:
    BrokerRequest(string method);


    string toString() const;

    map<string, string> getParameters() const{
        return parameters;
    }

    void addParameter(string key, string value) {
        this->parameters[key] =  value;
    }

    void addRequestArgument(string argument) {
        this->requestArguments.insert(argument);
    }

    string getRequestMethod() const {
        return requestMethod;
    }

    set<string> getRequestArguments() const {
        return requestArguments;
    }


private:
    string requestMethod;
    set<string> requestArguments;
    map<string, string> parameters;


};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H
