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

    vector<string> split(const string &s, char delim, vector<string> &elems, int max_occurrences = -1) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            if (elems.size() >= max_occurrences) {
                elems[1] += delim+item;
            } else elems.push_back(item);
        }
        return elems;
    }

    vector<string> split(const string &s, char delim, int max_occurrences = -1) {
        vector<string> elems;
        split(s, delim, elems, max_occurrences);
        return elems;
    }


    string &ltrim(std::string & str)
    {
        auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
        str.erase( str.begin() , it2);
        return str;
    }

    string &rtrim(std::string & str)
    {
        auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
        str.erase( it1.base() , str.end() );
        return str;
    }

    string &trim(std::string &str) {
        return ltrim(rtrim(str));
    }









}





#endif //BROKER_PROTOCOL_CLIENT_STRINGHELPER_H
