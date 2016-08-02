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

    /**
     * Returns all parameters of the reply
     * @return Returns a map containing the key value pairs.
     */
    map<string, string> getParameters() const{
        return parameters;
    }

    /**
     * Adds a parameter to the reply
     * @param key
     * @param value
     */
    void addParameter(string key, string value) {
        this->parameters[key] =  value;
    }

    /**
     * Returns the message of the reply
     * @return A string containing the message of the reply
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
     * @return An integer containing the 3 digit status code
     */
    int getStatusCode() {
        return statusCode;
    }

    /**
     * Returns a string not containing the Signature parameter.
     * This method is used when verifying the HMAC of a reply.
     * @return A string that is used by the BrokerSecurityModule
     */
    string toStringForSignatureValidation() const;

private:
    int statusCode;
    string message;
    map<string, string> parameters;
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLY_H

