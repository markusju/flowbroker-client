//
// Created by Markus Jungbluth on 20.06.16.
//


#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>
#include <cmath>
#include "BrokerDate.h"
#include "exceptions/DateValidationFailedErrorException.h"

void BrokerDate::checkTimeStamp(string date) {
    long start_millis = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    //cout << date << "\n";
    tm t = {};
    istringstream ss(date);
    ss >> get_time(&t, "%Y-%m-%dT%H:%M:%S");
    if (ss.fail()) throw DateValidationFailedErrorException("Invalid date");

    regex reg(".*\\.([0-9]{1,})Z$");
    smatch m;

    if (!regex_match(date, m, reg)) throw DateValidationFailedErrorException("Invalid Date!");
    //TODO: Check this..
    int stamp_millis = stoi(m[1].str());
    stamp_millis = stamp_millis / 1000;
    time_t tt1 = mktime(&t) - timezone;
    long stamp = tt1*1000+stamp_millis;

    long diff = start_millis - stamp;

    if (diff > 500) throw DateValidationFailedErrorException("Possible Replay Attack. Timestamps do not match!");
    return;

}

string BrokerDate::getCurrentTimeStamp() {
    long now_micros = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    time_t now_secs = now_micros / 1000000;
    //now_secs = now_secs + 1;
    stringstream ss;
    stringstream ss2;
    ss2 << fixed << (now_micros % 1000000) / 1000000.0;
    ss << std::put_time(gmtime(&now_secs), "%Y-%m-%dT%H:%M:%S") << ss2.str().erase(0,1) << "Z";

    //cout << ss.str() << "\n";
    //cout << now_secs << " " << now_micros << " " << ss.str();
    //return "123456789";
    return ss.str();
}
