//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_STRINGHELPER_H
#define BROKER_PROTOCOL_CLIENT_STRINGHELPER_H

#include <string>
#include <vector>
#include <locale>
#include <sstream>
#include <set>

using namespace std;

namespace stringHelper {
    /**
     * Splits a string on every occurence of a delimiter
     * @param s String to be splitted
     * @param delim Delimiter
     * @param elems Refrence to a vector in which the found occurences will be saved
     * @param max_occurrences max occurences
     * @return
     */
    vector<string> split(const string &s, char delim, vector<string> &elems, int max_occurrences = -1);
    /**
     * Splits a string on every occurence of a delimter
     * @param s String to splitted
     * @param delim Delimiter
     * @param max_occurrences max occurences
     * @return
     */
    vector<string> split(const string &s, char delim, int max_occurrences = -1);
    /**
     * Removes all whitespace at the start of a string
     * @param str
     * @return A string on which the function has been applied
     */
    string &ltrim(std::string & str);
    /**
     * Removes all whitespace at the end of a string
     * @param str
     * @return A string on which the function has been applied
     */
    string &rtrim(std::string & str);
    /**
     * Removes all whitespace at the start and end of a string.
     * @param str
     * @return A string on which the function has been applied
     */
    string &trim(std::string &str);
    /**
     * Joins all elements from a Set to a string
     * @param setValue
     * @param separator
     * @return A string containing all elements from the given set.
     */
    string joinSet(set<string> setValue, string separator = " ");
    /**
     * Joins all elements from a vector to string
     * @param vectorValue
     * @param separator
     * @return
     */
    string joinVector(vector<string> vectorValue, string separator = " ");

}





#endif //BROKER_PROTOCOL_CLIENT_STRINGHELPER_H
