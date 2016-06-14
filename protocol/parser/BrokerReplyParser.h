//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H

#include <string>
#include "../BrokerReply.h"

using namespace std;

class BrokerReplyParser {
public:
    BrokerReplyParser(string input);
    BrokerReply evaluate();

protected:
    vector<string> &split(const string &s, char delim, vector<string> &elems);
    vector<string> split(const string &s, char delim);
private:
    string input;

};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H
