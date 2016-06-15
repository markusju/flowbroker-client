//
// Created by Markus Jungbluth on 14.06.16.
//

#include <sstream>
#include <vector>
#include <numeric>
#include <iostream>
#include "BrokerReplyParser.h"
#include "../exceptions/BrokerReplyParseErrorException.h"


BrokerReplyParser::BrokerReplyParser() {
}

BrokerReply BrokerReplyParser::evaluate(string input) {
    istringstream inputstream(input);
    string line;

    BrokerReply reply;

    /*
     * 200 OK asdasd asd66565asd asdasd
     * Blah: blah
     * Nlaj: asdasd
     * asdasd454: asdsd545
     */


    if (getline(inputstream, line)) { // 200 OK asdasd asd66565asd asdasd
        vector<string> elems = this->split(line, ' ');


        //STATUS CODE
        try {
            reply.setStatusCode(stoi(elems[0]));
            elems.erase(elems.begin());
        } catch (invalid_argument){
            throw BrokerReplyParseErrorException("Non Numeric Status Code received!");
        }


        //STATUS MESSAGE
        if (!elems.empty()) {
            //Concatenate the remaining vectors to a String and set them as the message string..
            reply.setMessage(accumulate(elems.begin(), elems.end(), string("")));
        } else {
            throw BrokerReplyParseErrorException("No Message in reply.");
        }

    } else {
        throw BrokerReplyParseErrorException("No Reply found!");
    }

    //PARAMETERS
    while(getline(inputstream, line)) { //Parameters
        //Exit Condition...
        if (line.empty()) break;
        //cout << "LENGTH:" << line.length() << "VALUE:" << line << "DATA" << line.data() << "\n" ;

        vector<string> elems = this->split(line, ':', 2);

        if (elems.size() != 2) throw BrokerReplyParseErrorException("More than one colon in parameter string found.");

        string key = elems[0];
        string value = elems[1];

        if (key.length() < 1 || value.length() < 1) {
            throw BrokerReplyParseErrorException("Key and/or Value may not be empty!");
        }
        reply.addParameter(key, value);
    }

    return reply;
}


vector<string> &BrokerReplyParser::split(const string &s, char delim, vector<string> &elems, int max_occurrences) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (elems.size() >= max_occurrences) {
            elems[1] += item;
        } else elems.push_back(item);
    }
    return elems;
}


vector<string> BrokerReplyParser::split(const string &s, char delim, int max_occurrences) {
    vector<string> elems;
    split(s, delim, elems, max_occurrences);
    return elems;
}