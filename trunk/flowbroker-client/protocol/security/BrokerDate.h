//
// Created by Markus Jungbluth on 20.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERDATE_H
#define BROKER_PROTOCOL_CLIENT_BROKERDATE_H


#include <string>

using namespace std;

class BrokerDate {
public:
    void checkTimeStamp(string date);
    string getCurrentTimeStamp();

private:
    long gettime(string input);
    string puttime(long stamp);
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERDATE_H
