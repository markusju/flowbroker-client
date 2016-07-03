//
// Created by Markus Jungbluth on 14.06.16.
//

#include <sstream>
#include <vector>
#include <numeric>
#include <iostream>
#include "BrokerReplyParser.h"
#include "../exceptions/BrokerReplyParseErrorException.h"
#include "../../helper/stringHelper.h"


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
        vector<string> elems = stringHelper::split(line, ' ');


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
            reply.setMessage(accumulate(elems.begin(), elems.end(), string(""),
                                        [](const string& a, const string& b) {
                                            return a.empty() ? b : a + ' ' + b; //Insert Space again...
                                        }
            )
            );
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

        vector<string> elems = stringHelper::split(line, ':', 2);

        if (elems.size() != 2) throw BrokerReplyParseErrorException("More than one colon in parameter string found.");

        string key = stringHelper::trim(elems[0]);
        string value = stringHelper::trim(elems[1]);

        if (key.length() < 1 || value.length() < 1) {
            throw BrokerReplyParseErrorException("Key and/or Value may not be empty!");
        }
        reply.addParameter(key, value);
    }

    return reply;
}
