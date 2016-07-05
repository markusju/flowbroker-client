//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_STRINGHELPER_H
#define BROKER_PROTOCOL_CLIENT_STRINGHELPER_H

#include <string>
#include <vector>
#include <locale>
#include <sstream>

using namespace std;

namespace stringHelper {

    vector<string> split(const string &s, char delim, vector<string> &elems, int max_occurrences = -1);
    vector<string> split(const string &s, char delim, int max_occurrences = -1);
    string &ltrim(std::string & str);
    string &rtrim(std::string & str);
    string &trim(std::string &str);

}





#endif //BROKER_PROTOCOL_CLIENT_STRINGHELPER_H