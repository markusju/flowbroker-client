//
// Created by Markus Jungbluth on 17.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_MESSAGEAUTHENTICATIONCODE_H
#define BROKER_PROTOCOL_CLIENT_MESSAGEAUTHENTICATIONCODE_H


#include <string>

using namespace std;

class MessageAuthenticationCode {
public:
    MessageAuthenticationCode(string secret);

    /**
     * Returns a Message Authentication Code (HMAC) for the supplied message.
     * @param message Message the HMAC will be computed for.
     * @return A String containing the HMAC for the supplied message
     */
    string getMacForMessage(string message);

    /**
     * Validates a supplied HMAC against a message.
     * @param suppliedMac
     * @param message
     */
    void checkMacForMessage(string suppliedMac, string message);

private:
    string secret;

};


#endif //BROKER_PROTOCOL_CLIENT_MESSAGEAUTHENTICATIONCODE_H
