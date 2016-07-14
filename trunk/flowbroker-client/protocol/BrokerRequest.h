//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H
#define BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H

#include <string>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;


class BrokerRequest {



public:
    BrokerRequest(string method);
    BrokerRequest(const BrokerRequest &ref);


    string toString() const;

    vector<pair<string, string>> getParameters() const{
        return parameters;
    }

    void addParameter(string key, string value) {
        this->parameters.push_back(make_pair(key, value));
    }

    void addRequestArgument(string argument) {
        this->requestArguments.push_back(argument);
    }

    string getRequestMethod() const {
        return requestMethod;
    }

    vector<string> getRequestArguments() const {
        return requestArguments;
    }


private:
    string requestMethod;
    vector<string> requestArguments;
    vector<pair<string, string>> parameters;


};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H
