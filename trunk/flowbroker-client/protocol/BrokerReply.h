//
// Created by Markus Jungbluth on 13.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLY_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLY_H

#include <string>
#include <map>

using namespace std;

class BrokerReply {
public:
    BrokerReply();

    map<string, string> getParameters() const{
        return parameters;
    }

    void addParameter(string key, string value) {
        this->parameters[key] =  value;
    }

    string getMessage() const {
        return this->message;
    }

    void setMessage(string message) {
        this->message = message;
    }

    void setStatusCode(int statusCode) {
        this->statusCode = statusCode;
    }

    int getStatusCode() {
        return statusCode;
    }

private:
    int statusCode;
    string message;
    map<string, string> parameters;
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLY_H

