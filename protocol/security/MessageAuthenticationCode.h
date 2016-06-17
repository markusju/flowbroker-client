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

    string getMacForMessage(string message);
    void checkMacForMessage(string suppliedMac, string message);

private:
    string secret;

};


#endif //BROKER_PROTOCOL_CLIENT_MESSAGEAUTHENTICATIONCODE_H
