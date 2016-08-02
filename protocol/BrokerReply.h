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

    /**
     * Returns the message of the reply
     * @return
     */
    string getMessage() const {
        return this->message;
    }

    /**
     * Sets the message of the reply.
     * @param message
     */
    void setMessage(string message) {
        this->message = message;
    }

    /**
     * Sets the status code of the reply.
     * @param statusCode
     */
    void setStatusCode(int statusCode) {
        this->statusCode = statusCode;
    }

    /**
     * Returns the status code of the reply.
     * @return
     */
    int getStatusCode() {
        return statusCode;
    }

    /**
     * Returns a string not containing the Signature parameter.
     * This method is used when verifying the HMAC of a reply.
     * @return
     */
    string toStringForSignatureValidation() const;

private:
    int statusCode;
    string message;
    map<string, string> parameters;
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLY_H

