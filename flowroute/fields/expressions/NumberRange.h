//
// Created by Markus Jungbluth on 03.07.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_NUMBERRANGE_H
#define BROKER_PROTOCOL_CLIENT_NUMBERRANGE_H


#include <string>
#include <vector>
#include <set>

using namespace std;

class NumberRange {

public:
    void analyze(string input);
    void analyze(set<string> input);
protected:
    virtual void analyzeElement(string element) = 0;
    vector<string> getTokens();
private:
    vector<string> tokens;
};


#endif //BROKER_PROTOCOL_CLIENT_NUMBERRANGE_H
