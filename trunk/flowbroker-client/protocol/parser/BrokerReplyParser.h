//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H
#define BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H

#include <string>
#include <vector>
#include "../BrokerReply.h"

using namespace std;

class BrokerReplyParser {
public:
    BrokerReplyParser();
    BrokerReply evaluate(string input);

protected:
    vector<string> &split(const string &s, char delim, vector<string> &elems, int max_occurrences = -1);
    vector<string> split(const string &s, char delim, int max_occurrences = -1);
    string& ltrim(std::string & str);
    string& rtrim(std::string & str);
    string& trim(std::string & str);
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERREPLYPARSER_H
