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

    /**
     * Returns a list of all parameters.
     * @return A vector containing a pairs (key, value)
     */
    vector<pair<string, string>> getParameters() const{
        return parameters;
    }

    /**
     * Adds a parameter to the request.
     * @param key Key value of the parameter
     * @param value Corresponding value
     */
    void addParameter(string key, string value) {
        this->parameters.push_back(make_pair(key, value));
    }

    /**
     * Adds an argument to the request.
     * @param argument
     */
    void addRequestArgument(string argument) {
        this->requestArguments.push_back(argument);
    }

    /**
     * Returns the request method contained in the request.
     * @return A string with the request method
     */
    string getRequestMethod() const {
        return requestMethod;
    }

    /**
     * Returns all arguments contained in the request.
     * @return A vector containing all arguments
     */
    vector<string> getRequestArguments() const {
        return requestArguments;
    }


private:
    string requestMethod;
    vector<string> requestArguments;
    vector<pair<string, string>> parameters;


};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREQUEST_H
