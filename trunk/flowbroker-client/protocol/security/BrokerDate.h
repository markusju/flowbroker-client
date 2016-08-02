//
// Created by Markus Jungbluth on 20.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERDATE_H
#define BROKER_PROTOCOL_CLIENT_BROKERDATE_H


#include <string>

using namespace std;

class BrokerDate {
public:
    BrokerDate(long toleranceMillis);
    /**
     * Checks whether the supplied timestamp (ISO 8601) is within the preset tolerance.
     * @param date
     */
    void checkTimeStamp(string date);
    /**
     * Returns the current timestamp (ISO 8601)
     * @return A ISO 8601 compliant timestamp
     */
    string getCurrentTimeStamp();

private:

    long toleranceMillis;


    long gettime(string input);
    /**
     * Generates a ISO 8601 compliant string representing a timestamp in microseconds.
     * @param stamp
     */
    string puttime(long stamp);
};


#endif //BROKER_PROTOCOL_CLIENT_BROKERDATE_H
